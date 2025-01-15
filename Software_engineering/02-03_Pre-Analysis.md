# Models, Processes, and Measurement

![alt text](<imgs/Screenshot 2025-01-13 alle 13.19.13.png>)

In each stage (or phase) of a project, various techniques and tools are used, which may vary depending on the type and complexity of the project.

Development Framework --> the standardized techniques and tools to be used at each stage of the project (e.g. MADEJA (Software Development Framework of the Junta de Andalucía) )

![alt text](<imgs/Screenshot 2025-01-13 alle 14.43.06.png>)

Hito = Milestone (achievement that marks a significant point in a process)  
Entregable = Deliverable (tasks to describe a product, result, or outcome provided to a client, supervisor, or stakeholder)

**Milestone implies deliverable**

## Preliminar Specification
Preliminary Specification --> generates a deliverable (documentation) for identifying the needs of the future application  
TFEA Technique --> create questionnaires and conducting successive interviews with clients with the purpose of gathering information related to the problem domain that we need to solve (facilitate the specification of applications)

**Phases (made in cycle until project manager is satisfacted)**:
1. **meeting**: client/team meeting
    - general questions about the project
    - project manager asks the questions
    - the rest of the team takes notes
    - meeting not very lengthy
2. **specification informations**:
    - each engineer prepares an Individual Preliminary Specification (summary of the meeting)
    - the project manager collects all the preliminary specifications and creates a **Unique Specification**
3. **evaluation report**:
    - each member of the engineering team receives the Unique Specification and analyzes it separately
    - each engineer prepares an **Evaluation Report** of the specification, received by the project manager
4. **discussion meeting**:
    - the project manager organizes a meeting with the team to discuss the Evaluation Reports
    - during the meeting:
        - identify the possible processes for the project’s development
        - possible resources it may consume
        - the type of development (methodology)
        - potential profiles for interviews, etc.
    - goal: to create the questionnaires (one for each user/client profile) and conduct a technical and economic feasibility study of the project

![alt text](<imgs/Screenshot 2025-01-13 alle 16.01.49.png>)

**Result**: **deliverable** (documentation) with two parts:
1. **requirements and functions**
2. **data**

Based on these two parts, the project manager can estimate:
- **effort** --> number of people required to develop the project
- **duration** --> execution time

**COCOMO Model** --> technique based on the measurement of LDC (thousands of lines of code) and PF (Function Points) where the project manager responds to a table with pre-established metrics and weights (based on historical data from other previous projects)

**effort** (E) + **duration** (D) + **task list** (T) --> give **dependencies** between tasks (P) and **resources** (R) assigned to them (people and things)

P + R --> Pert and Gantt networks (planning the project)

![alt text](<imgs/Screenshot 2025-01-13 alle 16.35.34.png>)

**Contingency Plan**:
- developed in the Project Planning stage (phases 3 and 4)
- action plan for possible unexpected events that may occur during the execution and monitoring of the project
- identifies and describes:
    - project’s risks
    - the tasks and objectives that would be affected
    - the consequences
    - a description of the alternative to be carried out (action protocol)

## Refinement
refine informal model of the system’s requirements (functional and non-functional) and the data (before to start Design step) following one of two approaches:
- **structured** (Data Flow Diagram)
- **object-oriented** (UML)

# Software development methodologies
1.	Waterfall Model
2.	Prototype-based Model (Prototyping)
3.	Rapid Application Development Model (RAD Model)
4.	Evolutionary Models:
    - Spiral Model
    - Incremental Model (iterative incremental)
5.	Models based on formal methods

## Waterfall Model

![alt text](<imgs/Screenshot 2025-01-14 alle 14.34.05.png>)

- long time to complete all the phases
- useful for less complex problems (fast understanding of the problem between client and team)
- client does not have any early version of the product

## Prototype-based Model (Prototyping)

![alt text](<imgs/Screenshot 2025-01-14 alle 14.41.02.png>)

- useful for projects where user interfaces is crucial
- advantages:
    - start with collection of system and software requirements
    - engineers develop an initial prototype
    - client’s feedback refines the system requirements
    - reduces the risk of building systems that do not meet users’ needs
    - reduces costs and increases the probability of success
    - especially useful in the development of user interfaces
- disadvantages:
    - in early versions, omitted techniques to ensure software quality and maintainability
    - misunderstanding of the client about the prototype construction and its purpose new ideas
    - engineers use inappropriate tools to develop prototypes when only visual sketches are needed

## Rapid Application Development Model (RAD Model)

![alt text](<imgs/Screenshot 2025-01-14 alle 14.51.59.png>)

- useful for small-scale applications (60-90 days of construction)
- difficult to determine the number of teams needed
- requires close collaboration and commitment between clients and engineers
- appropriate for not complex systems
- not appropriate for systems with high interoperability

## Evolutionary Models

### Spiral Model

![alt text](<imgs/Screenshot 2025-01-14 alle 15.00.02.png>)

- mix of all the others
- slowly refines the system requirements as they are discovered
- based on Boehm’s Principle: all system requirements are impossible to know at the beginning, as most of them emerge during the design and implementation phases

### Incremental Model (iterative incremental)

![alt text](<imgs/Screenshot 2025-01-14 alle 15.02.49.png>)

- waterfall model applied iteratively
- each increment:
    - represents a new functionality added to the system
    - delivered a technical report at the end
- analysis phase of each new increment is the design phase of the previous increment

#### Iterative Incremental Model / Agile Methodologies

![alt text](<imgs/Screenshot 2025-01-14 alle 15.11.49.png>)

- SCRUM method --> useful when there is a well-coordinated and suitable team available
- advantages:
    - frequent deliveries (1-2 per month)
    - flexibility for easy changes
    - each sprint delivers a functional product
    - higher client involvement, increasing the likelihood of meeting requirements
    - clear responsibilities and close teamwork
- disadvantages:
    - requires careful management
    - project completion date and final price may vary
    - requires experienced and responsible team members

#### Iterative Incremental Model / Rational Unified Process – RUP Method (IBM)

![alt text](<imgs/Screenshot 2025-01-14 alle 15.32.19.png>)

- integrates rationally the appropriate processes and tools for each activity in the life cycle

Characteristics:
1.	Iterative and incremental model
2.	Driven by use cases
3.	Architecture-centered
4.	Component-based development
5.	Uses a standard modeling language
6.	It is an integrated process

## Models based on formal methods

- serves as complement to add semantics to models (diagrams), similar to how OCL (Object Contraint Language) is used in class diagrams
- necessary for verification, consistency, check implementations with specifications, security, reliability, critical systems, business logic
- examples:
    - temporal logic (Unity, TLA)
    - axiomatic specifications (Maude)
    - set-theoretic specifications (Z, Object-Z)
    - process algebras (CCS, CSP, LOTOS, pi-calculus)
    - other formalisms (state machines, Petri nets, Larch)
- JLarch (Java Larch) --> specify PRE/POST semantics in software components or software services
- Z language --> describe and model computing systems (math language)
