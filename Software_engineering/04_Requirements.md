# Requirements
**KEY**: Communication in requirement description  
if it is not correct --> Software project failure

## Requirement Gathering — Factors to consider
1. complexity of the problem
2. identify requirements by the client
3. communication difficulties between developers and users
4. communication difficulties among the development team members
5. requirements cannot be obtained but needed to construction process
6. changing nature of some requirements
7. new requirements during life cycle

## Software Requirements
**Software Requirements**:
- must achieve or possess (for a software) to satisfy a contract, standard, specification, or other formal document (IEEE, 1990)
- property that a developed or adapted software must have to solve a specific problem (SWEBOK Guide)

**requirements attribute** --> additional information in its specification

**requirements activities**:
- gathering --> capturing functionalities of the system from the user’s perspective
- analysis --> studying the user’s needs to obtain a detailed definition of the requirements
- specification --> documenting the required behavior of a software system (often using modeling notation or other language)
- validation --> examining the requirements to ensure they define the system that the client and users want

**actor** --> well-defined role (users, clients, software engineers, ...) that a person can play in the requirements process

**verifiability** --> verify if the software system meets the requirement

**other important properties of requirements** --> prioritization, traceability, unique identification, quantifiability

**software requirement specification document** --> contains a precise set of requirements (modeled in a specification language and validated) and serves as a contract between client desires and developers commit to building
- **SRS**: Software Requirements Specification (include functional and non-functional requirements)
- **ERS**: Especificación de Requisitos de Software (Spanish for Software Requirements Specification)

![alt text](<imgs/Screenshot 2025-01-15 alle 12.56.03.png>)

## Types of requirements
- **functional requirements**:
    - define specific functions the system must perform (e.g., print reports, store data)
    - describe the behavior of the system
    - usually come from user requirements
    - **key** --> obtain a complete catalog of functional requirements during the requirements activities with complete and consistent specifications
- **non-functional requirements**:
    - define system technical aspects (constraints, qualities, perfomance, external interfaces, maintenance, security, reliability, storage capacity, ...)
    - difficult to validate
    - classified into:
        - **constraints** --> any type of limitation that system developers face (e.g., operating system, hardware platform, available profiles, ...)
        - **qualities** --> characteristics of a system that are important to clients and users (e.g., performance, reliability, availability, ...)
        - **other classifications**: detailed vs. non-detailed, process vs. system, prioritized vs. non-prioritized, ...

![alt text](<imgs/Screenshot 2025-01-15 alle 13.19.26.png>)

## Requirements Activities
### 1. Requirement Gathering
- **objective** --> determine requirements to develop and acquire knowledge about the problem to be solved
- **key** --> communication between dev team and clients
- **information sources**:
    - general or high-level objectives
    - problem domain
    - actors involved in the process
    - operating environment (where the software will run)
    - organizational environment (to which the software must adapt)
- **requirements gathering techniques**:
    - interviews, scenarios, prototypes, group meetings, observation, studying the organization’s documentation, ...

### 2. Requirement Analysis
- **objective** --> describe carried out tasks to define and delimit each requirements precisely
    - detect and resolve conflicts between requirements
    - define software scope and determine which external elements it interacts with
    - develop system requirements to derive software requirements from them
- **tasks involved**:
    - **classify requirements** --> group requirements into categories and prioritize them
    - **conceptual modeling** --> represent requirements in a specific language or notation to aid understanding
    - **position requirements within system architecture** --> assign responsibilities to system elements to fulfill each requirement, which can reveal new ones
    - **negotiate requirements** --> identify and resolve conflicts between requirements
    - **conflict resolution techniques** --> eliminate redundancies, inconsistencies, and disagreements

### 3. Requirement Specification (Requirements Attributes)
- **objective** --> describe the system requirements to be developed in a complete manner
- serves as a contract between clients and developers
- **not included**:
    - costs
    - delivery deadlines
    - validation and verification criteria
    - adaptation procedures
- **documents**:
    - **system definition**:
        - high-level user requirements
        - from the problem domain perspective
    - **system requirements**:
        - formal specification of system requirements
        - system functionality
        - performance specifications
        - security requirements
        - user interface definitions
        - distinction between software and hardware tasks
    - **Software Requirements Specification (SRS)**:
        - explicitly defines everything the software must do
        - uses modeling notations or specification languages (e.g., UML)

### 4. Requirement Validation
- **objective** --> examine if requirement documents comprend what users expect to receive (easier if specification languages or modeling notations are used)
- **methods for validation**:
    - **requirements review** --> review documents, including someone from the client side
    - **prototyping** --> show functionality of requirements
    - **model validation** --> verify if consistent and accurately reflects system requirements
    - **acceptance testing** --> develop a plan to establish how each requirement should be validated

## Conceptual Modeling
- entities represent real-world objects
- often graphically represented using formal models and pre-established notation
- requires a language and rules to guide the use of elements
- **benefits**:
    - enhances understanding of requirements
    - identifies inconsistencies
    - facilitates discussion among stakeholders through visual models
- **different notations**: use cases, entity-relationship models, UML class diagrams, formal notations, ...

### Use Cases
- most commonly used for modeling and capturing functional requirements
- part of the UML language
- **main purpose**: define the behavior of system entities
- **central elements**: use cases and actors

![alt text](<imgs/Screenshot 2025-01-15 alle 21.00.13.png>)

### Entity-Relationship Models
- conceptual modeling of data
- focused on designing database schemas
- **central elements**: entities (and their attributes) and relationships

![alt text](<imgs/Screenshot 2025-01-15 alle 21.01.15.png>)

### Analysis Class Diagrams
- static conceptual modeling (functional requirements)
- do not include implementation details for requirements modeling
- **types**:
    - **entity class** --> models information managed in the system
    - **interface class** --> models interaction between system and actors
    - **control class** --> represents coordination, sequencing, transactions, and control of other classes

![alt text](<imgs/Screenshot 2025-01-15 alle 21.05.42.png>)

### Formal Notations
- **importance**: precise notation without ambiguities
- **characteristics**:
    - notations with no room for misinterpretation
    - based on mathematical notations
- **examples**: Z, B, CSP, CCS, Pi-calculus, logic, ...

![alt text](<imgs/Screenshot 2025-01-15 alle 21.07.16.png>)

## Requirements Process Management
- **development time**:
    - high pressure
    - short development cycles
    - competitive markets
- significant impact on requirements process
- **iterive evolution of requirements** untill quality satisfaction
- **requirements baselines** --> defined within the project
    - set of requirements that must be included in a product delivery
    - provides history of changes and versions
- **requirements tracking**:
    - evaluate and prevent the impact of possible changes in the software
    - track requirement status (specified, analyzed, verified)
    - tracking matrix shows correspondence between requirements and test cases or components
    - low relationship values indicate poor tracking, while high values suggest complexity
- **requirements metrics**:
    - used in managing requirements and system changes or updates
    - methods include CMMI, Six Sigma, etc.
    - types of metrics: scope, growth, stability, progress, consistency, complexity, quality, ...
- **Tools for Requirements Management**:
    - **advantages**:
        - improve tracking, maintenance, and automation of requirements
        - reduce costs, errors, and improve quality and productivity
        - support reuse and ensure compliance with quality standards
    - **features**:
        - manage versions, changes, and requirements data
        - link requirements to other elements and track their status
        - support searches, access control, verification, and acceptance
        - facilitate communication and simultaneous use by multiple users
        - offer reporting capabilities
