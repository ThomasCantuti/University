import requests
import datetime

def scrap_ryanair_data():
    url = ("https://www.ryanair.com/api/booking/v4/it-it/availability?ADT=1&TEEN=0&CHD=0&INF=0&Origin=AGP&Destination=BLQ&promoCode=&IncludeConnectingFlights=false&DateOut=2025-02-06&DateIn=&FlexDaysBeforeOut=1&FlexDaysOut=1&FlexDaysBeforeIn=1&FlexDaysIn=1&RoundTrip=false&ToUs=AGREED")

    # 1. Esegui la GET sull’endpoint
    try:
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Brave/1.28.105 Chrome/92.0.4515.131 Safari/537.36",
            "Accept": "application/json",
            "Accept-Language": "it-IT,it;q=0.9"
        }
        response = requests.get(url, headers=headers)
        print(response.status_code)
        print(response.text)  # oppure print(response.json()) se ritorna JSON
        #response = requests.get(url, headers=headers)
        response.raise_for_status()
        data = response.json()
    except requests.exceptions.RequestException as e:
        print(f"Request error: {e}")
        return []
    except ValueError as e:
        print(f"JSON parse error: {e}")
        return []
    
    # 2. Se vuoi usare la data/ora fornita da Ryanair per calcolare differenze
    #    la trovi in data["serverTimeUTC"]. Esempio:
    server_time_utc_str = data.get("serverTimeUTC", None)

    if not server_time_utc_str:
        # Se, per qualche motivo, non esiste, puoi usare datetime.utcnow() come fallback
        server_time_utc = datetime.datetime.now(datetime.UTC)
    else:
        # Converte la stringa in datetime (rimpiazza la 'Z' con +00:00 per compatibilità ISO)
        server_time_utc = datetime.datetime.fromisoformat(
            server_time_utc_str.replace("Z", "+00:00")
        )
    
    # 3. Itera sui viaggi (in teoria, "trips" di solito è un array con un solo oggetto,
    #    ma facciamo un loop per sicurezza).
    all_flights_data = []
    for trip in data.get("trips", []):
        origin = trip.get("origin")
        destination = trip.get("destination")
        
        # Ogni trip ha un elenco di date
        for date_info in trip.get("dates", []):
            # La data "macro" di partenza (es. 2025-02-10T00:00:00.000)
            date_out_str = date_info.get("dateOut")
            # Da qui potresti volendo estrarre la data pura (YYYY-MM-DD)  
            
            # Ogni dataOut ha un elenco di flights
            for flight in date_info.get("flights", []):
                
                # --- Lettura campi di base ---
                flight_number = flight.get("flightNumber")
                duration = flight.get("duration")  # es. "02:25"
                
                # Il prezzo si trova dentro "regularFare" -> "fares" -> ...
                price = None
                regular_fare = flight.get("regularFare", {})
                fares = regular_fare.get("fares", [])
                if fares:
                    # Normalmente il primo fare di tipo "ADT" è quello che ti interessa
                    price = fares[0].get("amount", None)  

                # Orario di partenza e arrivo in formato UTC (stringa tipo "2025-02-10T06:15:00.000Z")
                time_utc_list = flight.get("timeUTC", [])
                if len(time_utc_list) == 2:
                    departure_utc_str = time_utc_list[0]
                    arrival_utc_str = time_utc_list[1]
                    
                    # Converto in datetime per poter calcolare i days_before_flight e il weekday
                    departure_dt = datetime.datetime.fromisoformat(
                        departure_utc_str.replace("Z", "+00:00")
                    )
                    arrival_dt = datetime.datetime.fromisoformat(
                        arrival_utc_str.replace("Z", "+00:00")
                    )

                    # --- days_before_flight ---
                    # Esempio: differenza in giorni tra il server_time_utc e la data/ora di partenza
                    days_before_flight = (departure_dt - server_time_utc).days
                    
                    # --- weekday ---
                    # Lunedì, Martedì, ecc. (in inglese: Monday, Tuesday, ...)
                    weekday = departure_dt.strftime("%A")
                    
                else:
                    # Se per qualsiasi motivo mancano i campi, gestisci fallback
                    departure_dt = None
                    arrival_dt = None
                    days_before_flight = None
                    weekday = None

                # hour_of_check -> l'ora (0-23) in cui lo script/utente ha interrogato l'API
                hour_of_check = server_time_utc.hour

                # holiday_period -> non ricavabile direttamente: lascia None o logic custom
                holiday_period = None
                
                # 4. Salva (o stampa) i dati utili
                flight_data = {
                    "origin": origin,
                    "destination": destination,
                    "duration": duration,
                    "days_before_flight": days_before_flight,
                    "weekday": weekday,
                    "hour_of_check": hour_of_check,
                    "holiday_period": holiday_period,
                    "price": price
                }
                all_flights_data.append(flight_data)

    return all_flights_data


if __name__ == "__main__":
    flights = scrap_ryanair_data()
    for f in flights:
        print(f)