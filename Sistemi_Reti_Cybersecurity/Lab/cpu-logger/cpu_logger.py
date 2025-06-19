"""
Implement a program in Python called cpu_logger that logs the CPU usage of the system over time.
Use the function cpu_percent of the psutilmodule to get the current CPU usage of the system.
cpu_logger accept a single argument, interval, which indicates the time interval between logs.
cpu_logger logs the CPU usage of the system every 5 seconds.
Run cpu_logger as a user Linux service with systemd.

How to run:
python cpu_logger.py --interval 5
"""

import argparse
import time
import logging
from datetime import datetime
from psutil import cpu_percent

def setup_logging():
    """Configure logging to file and console"""
    logging.basicConfig(
        level=logging.INFO,
        format='%(asctime)s - %(message)s',
        handlers=[
            logging.FileHandler('/tmp/cpu_usage.log'),
            logging.StreamHandler()
        ]
    )

def cpu_logger(interval):
    """Log CPU usage at specified intervals"""
    setup_logging()
    logger = logging.getLogger(__name__)
    
    logger.info(f"Starting CPU logger with interval: {interval} seconds")
    
    try:
        while True:
            cpu_usage = cpu_percent(interval=1)
            logger.info(f"CPU Usage: {cpu_usage:.2f}%")
            time.sleep(interval)
    except KeyboardInterrupt:
        logger.info("CPU logger stopped by user")
    except Exception as e:
        logger.error(f"Error: {e}")

def main():
    parser = argparse.ArgumentParser(description='Log CPU usage over time')
    parser.add_argument('--interval', type=int, default=5, 
                       help='Time interval between logs in seconds (default: 5)')
    
    args = parser.parse_args()
    cpu_logger(args.interval)

if __name__ == "__main__":
    main()