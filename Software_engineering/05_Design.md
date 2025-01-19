# Design

**design definition (IEEE 1990)**:
- process of defining architecture, components, interfaces, and other characteristics of a system or component
- result of this process

**main goal** --> specify components, modules, or parts of software and how they communicate

2 main subprocesses of design:
- **architecture design** (or high-level design) --> decompose and organize the system into different components
- **detailed design** --> describe the specific behavior of each software component identified in the previous process

![alt text](<imgs/Screenshot 2025-01-16 alle 11.23.34.png>)

## Fundamental Design Concepts
### Abstraction
- **different levels of detail** --> from high level abstraction to a level of detail closer to implementation
- **3 types**:
    - **data abstraction** --> object as a set of data
    - **procedural abstraction** --> sequence of steps that make up a specific process
    - **control abstraction** --> control system of software without describing the internal workings
- all 3 types used

![alt text](<imgs/Screenshot 2025-01-16 alle 11.43.56.png>)

### Component
functional part of a system that:
- hides how it works inside (implementation details)
- provides its functions through interfaces

it is usually replaceable, self-contained, and can be reused in software design

### Interface
defines how two softwre parts communicate and how one part interacts with the other

### Modularization and Decomposition
- **modularization** --> **divide** a complex problem into smaller **independent** parts/modules and **integrate them** to make it easier to solve
- **properties to evaluate modularity**:
    - **decomposition** --> break down high-level components into lower-level components (can be recursive)
    - **composition** --> reverse of decomposition
    - **understandability** --> easier to design programming elements that can be understood without knowing the rest of the modules
    - **continuity** --> small change in the specification should result in a small change in the system's implementation
    - **protection** --> errors or execution issues should be confined to the module where the error occurred, or affect as few modules as possible in the system
- **measuring modularity**:
    - the goal is to minimize dependencies between modules
    - dependencies are measured using:
        - **coupling** --> level of interconnection between modules (goal -> low coupling)
        - **cohesion** --> how closely the elements within a module are related to performing a common function (goal -> high cohesion)

![alt text](<imgs/Screenshot 2025-01-16 alle 12.15.35.png>)

![alt text](<imgs/Screenshot 2025-01-16 alle 12.16.06.png>)

### System Architecture (ISO/IEC 42010:2007)
fundamental organization of the system represented by:
- components
- relationships between components and the environment
- principles guiding design and implementation

**standard** that provides a general framework to:
- identify stakeholders and their interests
- select and identify viewpoints for the interests
- document the architecture views that satisfy the viewpoints
- document inconsistencies between views
- establish a basis for decisions regarding the architecture

**different approaches** (based on the type of project):
- **functional architecture** --> describes the different functions of the system
    - **vertical or user-functional** --> decomposition based on grouping functionalities derived from functional requirements
    - **cross-functional** --> includes aspects that are not specific to certain functional groups
- **database architecture**
- **hardware and network architecture** that make up the system
- **architectural styles** --> different ways to organize components in a software architecture
    - **filter-pipeline or batch processing** --> a component takes input, processes it, and passes it to another component

    ![alt text](<imgs/Screenshot 2025-01-16 alle 13.05.43.png>)

    - **object-oriented** --> system organized using a class diagram

    ![alt text](<imgs/Screenshot 2025-01-16 alle 13.08.05.png>)

    - **event-based architecture** --> components send out events, and other components can sign up to be notified when certain events happen

    ![alt text](<imgs/Screenshot 2025-01-16 alle 13.07.27.png>)

    - **layered architectures** --> components arranged in layers

    ![alt text](<imgs/Screenshot 2025-01-16 alle 13.08.40.png>)

    - **repository or shared data systems** --> central data structure accessed by various components

    ![alt text](<imgs/Screenshot 2025-01-16 alle 13.09.02.png>)

    - **process control** --> adds control components (like a feedback loop) to manage the behavior of system components

    ![alt text](<imgs/Screenshot 2025-01-16 alle 13.09.21.png>)

    - **distributed processes** --> system's functions split across different machines, common in client-server and peer-to-peer (P2P) architectures

    ![alt text](<imgs/Screenshot 2025-01-16 alle 13.10.46.png>)

**architectural languages (ADLs = Architecture Description Languages)**:
- define components, connectors, and communication links in software architectures
- help with verification and rapid prototyping
- **types**:
    - **general-purpose** --> used for various types of software architectures
    - **domain-specific (DSSA = Domain-Specific Software Architectures)** --> tailored for specific domains
- **examples**: ACME, ArTek, Rapide, MetaH, SysML, Darwin, UML, Wright

### Design Notations
- many notations to describe a system's architecture:
    - **structured methods**
    - **object-oriented methods**
    - **mixed options** that combine different notations for different parts of the system
- common notations:
    - object-oriented methods
    - UML as a modeling language
    - databases modeled using entity-relationship diagrams
    - flowcharts or pseudocode to define algorithms
    - prototypes and UI navigation through storyboards

## Design Methods
### Structured Methods
functional decomposition from the complete system down to the necessary level of detail for implementation (based on a top-down approach)

**key aspects**:
- functional decomposition (specification of processes)
- data modeling (specification of data)
- representation of information flow (specification of control)

**Types of structured methods**:
- **Data Flow Diagrams (DFD)**
    - represent data flows and the transformations applied to them
    - nodes --> processes
    - vertices --> inputs/outputs of processes
    - can be broken down into sub-diagrams at different levels, following a top-down approach
    - **elements**:
        - **processes** --> describe system functionality
        - **stores** --> define data used by the system
        - **external entities** --> sources or destinations of information
        - **data flows** --> represent communications between system elements
    
    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.39.48.png>)

- **Entity-Relationship Diagrams (E/R)**
    - conceptual data modeling
    - focused on designing database schemas
    - **key elements**:
        - **entities (and their attributes)**
        - **relationships**

    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.40.55.png>)

- **Data Dictionary**:
    - contains the data used by the system
    - primarily describes the data structure
    - also provides information on restrictions, access, authorizations, transactions, relationships with users, etc.
    - **metadata** (data about the data)

    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.42.41.png>)

- **Structure Diagrams**:
    - represent the modular structure of a structured system
    - functional decomposition in a hierarchical manner
    - information about execution sequence, control, and data (sent or received)

    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.44.54.png>)

### Structured Methods to Describe Each Module
- **Transition tables**:
    - define rules in a tabular format with actions to be performed
    - rules depend on conditions set by certain input variables

    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.50.54.png>)

- **Decision trees**: similar to decision tables but in a tree format

    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.54.13.png>)

- **State diagrams**: originally developed to describe finite automata, now used in many areas
    
    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.55.26.png>)

- **Other description methods**: pseudocode, flowcharts, etc.

    ![alt text](<imgs/Screenshot 2025-01-17 alle 16.57.21.png>)

### Data-Oriented Methods
- many systems which manage data
- data organized in files or databases
- E/R model used for analysis and as a starting point in database design

![alt text](<imgs/Screenshot 2025-01-17 alle 17.08.29.png>)

### Object-Oriented Design
- **object-oriented programming languages** share common features and principles
- **object-oriented design methods** have emerged, each with its own tools and notation
- **UML**  --> standard language for modeling, specifying, constructing, and documenting software systems based on object-oriented principles

- **properties**:
    - **abstraction** --> simplifies complexity by defining classes that group common properties and actions
    - **inheritance** --> creates new classes based on existing ones, inheriting features and adding new ones
    - **encapsulation** --> organizes data and actions, so users interact only with the public interface without needing to understand the details
    - **polymorphism** --> allows methods with the same name to behave differently

- **UML** --> describe systems using models and diagrams
    - **Model** --> system abstracted view described at an appropriate level of detail
    - **Diagram** --> graphical representation of a model or set of models
        - **structure diagrams** --> describe the system’s physical (static) structure (e.g. Classes, Objects, Components, Composite Structure, Packages, Deployment)
        - **behavior (dynamic) diagrams** --> describe how the elements of the system interact (e.g. Activity, Communication, Interaction, Sequence, State, Timing, Use Cases)

    - **UML Diagrams**:
        - **Use Case Diagram** --> represents system functional requirements using use cases, actors, and their relationships

        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.43.15.png>)

        - **Class Diagram (key diagram)** --> shows a set of classes, interfaces, and collaborations with their relationships (classes define common features of a group of objects)

        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.48.12.png>)

        - **Object Diagram** --> shows objects and their relationships at a specific point in time (represents an instance of a class diagram)

        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.49.28.png>)

        - **Component Diagram** --> describes the components of an application, their interrelations, and public interfaces

        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.50.38.png>)

        - **Interaction Diagrams**:
            - **Sequence Diagram** --> models the order of messages between system participants
            - **Communication Diagram** --> shows object organization and message passing between them
        
        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.51.49.png>)

        - **State Diagram** --> describes the states an object can be in and transitions between them (useful for showing complex class behavior)

        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.53.34.png>)

        - **Deployment Diagram** --> shows the physical system architecture and how nodes are connected

        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.54.17.png>)

        - **Activity Diagram** --> represents business processes and data flows

        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.55.16.png>)

        - **Package Diagram** --> displays the organization of system elements into packages
    
        ![alt text](<imgs/Screenshot 2025-01-17 alle 17.56.02.png>)

        - **Object Constraint Language (OCL)** --> extends UML semantics with constraints and query expressions and describes:
            - **invariants** (in classes, types, or interfaces)
            - **preconditions and postconditions** (in methods)
            - **navigation schemes** for attributes and operations
        
        ![alt text](<imgs/Screenshot 2025-01-17 alle 18.05.21.png>)

## Patterns

**Patterns** --> recurring problems and their solutions, so we can reuse the solution without rethinking it

### Pattern Languages
---
- **User Interface Patterns** --> describe human-computer interaction (e.g. MVC, MVP)
- **Design Patterns** --> set of classes and their relationships for object-oriented models (e.g. Observer, Composite, Mediator, Proxy)
- **Programming Idioms** --> tips or rules for writing code in programming languages (e.g. incrementing a counter, changing a variable’s value)
- **System Integration Patterns (EAI)** --> define communication and coordination between systems (e.g. file exchange, remote invocation, database sharing)
- **Workflow and Organization Patterns** --> describe workflows and processes in business systems (e.g. organizing personnel, synchronizing processes, exclusive process selection)

### Design Patterns
---
- **Design Patterns** --> solutions to recurring problems in terms of classes, interfaces, objects, and interactions between them

**Conditions for a Solution to Be Considered a Pattern**:
- **The Rule of Three** --> must be tested at least three times or in different domains
- comparison with other possible solutions in the same domain, showing their weaknesses

**Advantages**:
- reuse of entire architectures
- provides a common vocabulary for designers
- improves learning by grouping existing knowledge

**Disadvantage**:
- steep learning curve

#### Types of Design Patterns
---
- **Creation Patterns** --> solutions for creating objects
    - **singleton** --> ensures a class has only one instance and provides a global access to it (e.g. only one database connection instance)
    - **factory method** --> defines how to create objects, but allows subclasses to change the type of objects created (e.g. create different shapes like circles and squares)
    - **abstract factory** --> provides a way to create related objects without specifying their exact classes (e.g. produce related buttons like dark mode, light mode)
    - **builder** --> separates the process of building an object from its final appearance, allowing for different object versions (e.g. build a complex object like a car with options)
    - **prototype** --> allows creating new objects by copying existing ones, without needing to know their class (e.g. clone an object with similar properties)
- **Structural Patterns** --> help model how classes and objects combine to create more complex structures
    - **adapter** -->  changes the interface of one object so that it can work with another object (e.g. convert a legacy system API to a new one)
    - **bridge** --> separates the interface from its implementation, allowing both to evolve independently (e.g. separate database interface from storage logic)
    - **composite** --> combines objects into tree-like structures that can be treated as a single object (e.g. a tree of UI components like buttons and panels)
    - **decorator** --> adds additional functionality to objects at runtime, offering flexibility over using inheritance (e.g. add new features to a car like sports mode)
    - **facade** --> simplifies interactions with a subsystem by providing a unified interface (e.g. simplify complex system calls with a single method)
    - **flyweight** --> reduces memory usage by sharing common data between similar objects (e.g. share font data for text rendering)
    - **proxy** --> acts as an intermediary or placeholder to control access to another object (e.g. control access to sensitive system operations)
- **Behavioral Patterns** --> focus on modeling communication and interaction between system objects
    - **chain of responsibility** --> passes a request through a chain of handlers, allowing multiple objects to handle the request (e.g. log messages processed by different handlers)
    - **command** --> encapsulates a request as an object, allowing clients to queue requests or perform undo operations (e.g. queue a series of user actions like undo/redo)
    - **interpreter** --> defines the rules (grammar) of a language and interprets it to perform actions (e.g. parse mathematical expressions and evaluate)
    - **iterator** --> provides a way to access elements in a collection one by one, without revealing the collection’s internal structure (e.g. loop through items in a collection)
    - **mediator** --> centralizes communication between objects, reducing direct interactions between them (e.g. centralize control of chatroom messages)
    - **memento** --> saves an object’s state so it can be restored later, useful for undo operations (e.g. save and restore game state)
    - **observer** --> notifies and updates dependent objects whenever an object’s state changes (e.g. update UI when data changes)
    - **state** --> changes an object’s behavior when its internal state changes, making it appear as though it is a different object (e.g. change behavior when a ticket status updates)
    - **strategy** --> defines different algorithms and allows them to be switched out easily (e.g. choose the best sorting algorithm)
    - **template method** --> defines a general algorithm structure, but lets subclasses implement specific steps (e.g. define a general recipe, let subclasses modify steps)
    - **visitor** --> allows new operations to be added to objects without modifying the objects themselves (e.g. add operations to a class structure like tax calculation)

- **Abstract Factory (creation pattern)** --> provides a common interface to create related objects without specifying their exact class

![alt text](<imgs/Screenshot 2025-01-18 alle 18.58.55.png>)

- **Composite (structural pattern)** --> used to build hierarchies of objects that share an interface (some elements can contain others)

![alt text](<imgs/Screenshot 2025-01-18 alle 19.04.54.png>)

- **Observer (behavioral pattern)** --> defines a one-to-many relationship where changes in one object notify all dependent objects

![alt text](<imgs/Screenshot 2025-01-18 alle 19.05.29.png>)

- **Strategy (behavioral pattern)** --> implements interchangeable algorithms that share a common interface

![alt text](<imgs/Screenshot 2025-01-18 alle 19.06.12.png>)

- **Antipatterns** --> prevent common design mistakes and describe problems where disadvantages outweigh the benefits
    - **Sequential Coupling** --> building a class that requires methods to be called in a specific order
    - **Yo-Yo Problem** --> creating structures (e.g., inheritance) that are difficult to understand due to excessive fragmentation
    - **Blob** --> a class or component that holds too much information about properties and operations (monolithic solution)

![alt text](<imgs/Screenshot 2025-01-18 alle 21.23.23.png>)

## Software Frameworks, Plug-ins, and Components
Frameworks, plug-ins, and components allow for the reuse of complete designs and architectures (more powerful than reusing individual classes)

### Frameworks
---
**Framework** --> set of classes, interfaces, and their relationships that provide a **reusable design** intended to be extended (not used as a final application) and abstract entities, states, and behaviors within a domain

**Popular Frameworks**:
- **User Interface Development** --> focuses on the interface while abstracting components behavior
- **JUnit** --> framework for unit testing Java code
- Eclipse, Apache Struts, Spring, etc.

**Disadvantages** --> more expensive to develop than a normal application and have a steep learning curve

### Plug-ins
---
**Plug-in** --> complete application, module, or component that interacts with a host application to extend or adapt its behavior (current trend for improving software reuse)

**Popular Plug-ins**:
- Browser extensions for video, audio, etc.
- For Eclipse or NetBeans

**Implementation** --> follows the **Inversion of Control** pattern (host application doesn’t need to be modified or know the plug-in’s implementation details)

### Components
---
**Component** --> functional unit that can be added to an application (built by composing interfaces) for multiple uses, described by a specification that defines its interfaces and developed by third parties without sharing source code

**Goal** --> assemble components to build a custom system solution (Component-Based Software Engineering, CBSE)

**Examples**: JavaBeans, Microsoft COM, CORBA, SOAP components, etc.

## Design by Contract
**design by contract** --> each method has a precondition and a postcondition that must be met at input and output, respectively, using assertions (formal constraints) to check these conditions (formal agreement (contract) between a class and its clients)

## Evaluation and Metrics in Design
**Goal**:
- evaluate and measure different quality criteria
- compare design alternatives
- used criteria: cohesion, coupling, quality factors, etc.
- used methods and standards for quality to generate or calculate metrics
- **evaluationa dn validation** --> using quality and design metrics, mathematical validation, and reviews and inspections

**Design Factors**:
- **Extensibility** --> add new features without more changes to the architecture
- **Robustness** --> handle invalid and unpredictable inputs
- **Reliability** --> perform consistently under certain conditions and for a specified time
- **Fault Tolerance** --> system’s strength and ability to recover from failures
- **Compatibility** --> operate with other products
- **Reusability** --> use designs with similar needs

**Design Complexity Metrics**:

$HK_m = C_m \cdot (fan\_in_m \cdot fan\_out_m)^2$

- $HK_m$ --> structural complexity
- $C_m$ --> complexity of the module (e.g., lines of code)
- $fan\_in_m$ --> number of modules that call module m
- $fan\_out_m$ --> number of modules that are called by module m

**metrics based on morphology (graph theory)** --> measures size (in nodes and arcs), depth of nesting, width, and the ratio of arcs to nodes

**metrics for object-oriented design (MOOD)** --> measures encapsulation, inheritance, polymorphism, and message passing

Examples of MOOD Metrics:
- **Method Hiding Factor (MHF)** --> measures encapsulation
- **Attribute Hiding Factor (AHF)** --> measures encapsulation
- **Method Inheritance Factor (MIF)** --> measures inheritance
- **Attribute Inheritance Factor (AIF)** --> measures inheritance
- **Polymorphism Factor (PF)** --> measures polymorphism by calculating the ratio of overridden inherited methods to possible polymorphisms