# Testing
**Software testing** --> <u><b>empirical</b></u> and <u><b>technical</b></u> investigations aimed at providing <u><b>objective and independent information</b></u> about the product’s <u><b>quality</b></u> to a stakeholder

- **empirical** --> based on experience and experimentation
- **technical** --> involves applying procedures and resources related to a specific science
- **objective and independent information** --> focuses on the element itself, regardless of what we think or feel about it
- **quality** --> inherent properties that allow judgment or analysis of its value (e.g., customer expectations, usability, reliability, cost, efficiency, and compliance with standards)

\+ test --> \+ quality (less expensive && more time and effort)

**software test** --> any process aimed at checking the software’s quality by identifying defects within it while executing the software

**goal** --> minimize the percentage of bugs

**test case** --> set of inputs, execution conditions, and expected results, developed for a specific purpose, such as testing a particular path in a program or verifying compliance with a certain requirement

**exhaustive test or complete test** --> ideal test that ensures all possible causes of failures have been checked

## Fundamental Concepts
- **failure** --> undesirable effect observed in the functions or performance of software
- **bug (or defect)** --> imperfection in the software that causes incorrect behavior

**Testing** --> process of demonstrating the presence of a bug

**Debugging** --> process of discovering the exact location of the bug and modifying the software to eliminate it

**Oracle** --> agent (human or not) capable of determining if a test has passed

**Traceability or Tracking** --> ensures that each requirement is linked to the corresponding functionality throughout development

## Limitations in Software Testing
- impossibility of exhaustive testing (impossible to test all possible cases)
- limitations due to the nature of tests (some errors are detectable through white-box testing but not through black-box testing)
- test case selection (deciding on the most appropriate test cases can be difficult)
- test team selection (tests should be conducted by independent)
- test completion (hard to determine when to stop testing)

## Testing and Risk
- rigorous and consistent testing --> minimizes risk
- if software controls a dangerous process --> obvious risk
- other less obvious risks:
    - decision-making
    - data storage
    - management of sensitive data
    - etc.
- main risks for an organization:
    - damage to reputation
    - financial losses
    - legal consequences

## Testing Techniques
discover the maximum number of software failures through systematic testing

- white-box / black-box / gray-box -> too general
- exhaustive classification -> more specific

**coverage** --> percentage of the software that has been tested (e.g., 95% is considered sufficient)

![alt text](<imgs/Screenshot 2025-01-20 alle 16.43.54.png>)

### Black-Box Testing
- tests the software by providing input and observing output, without knowledge of the internal code
- focus -> ensuring the software meets requirements and performs correct functions
- easy to automate
- high maintenance costs
- may leave some code untested if not designed properly
- uses equivalence classes to group inputs

### White-Box Testing
- requires knowledge of the internal workings of the software
- focus -> testing different parts of the code, aiming to cover all possible execution paths or alternatives

### Gray-Box Testing
- special type of black-box testing where partial knowledge of the code is needed
- if the tester knows part of the code --> better tests can be performed

### Exhaustive Classification
- **Techniques Based on Intuition and Experience**
    - ad hoc testing (custom-made tests)
    - exploratory testing (designed, executed, and modified dynamically based on experience)
- **Techniques Based on Specification**
    - equivalence partitions
    - boundary value analysis
    - robustness testing
    - decision tables
    - finite state machine-based tests
    - formal specification-based tests
    - random testing
- **Techniques Based on Code**
    - control flow coverage testing
    - data flow coverage testing
- **Techniques Based on Errors**
    - error guessing
    - mutation testing (testing with both original and mutated code)
- **Statistical Techniques**
    - clean room testing (statistical control of the number of failures)
- **Techniques Based on Usage**
    - operational profile testing (reproducing the software’s operating environment as faithfully as possible)
    - software reliability testing

## Testing Levels
![alt text](<imgs/Screenshot 2025-01-20 alle 17.09.34.png>)

- **based on the object (the element being tested):**
    - unit testing
    - integration testing
    - system testing
- **based on the objective:**
    - acceptance testing
    - installation testing
    - alpha and beta testing
    - conformance testing
    - regression testing
    - performance testing
    - etc.

### Based on the Object
**testing object** --> element being tested (module, group of modules, or the entire software system)

**Unit Testing**:
- software component specifically created to verify the functioning of a system component
- goal -> ensure individual parts of the software are correct
- traditional methods -> developers consider the code ready for testing once it’s prepared
- modern methods (like Extreme Programming) -> tests are implemented even before writing the code to be tested

**Integration Testing**:
- after unit tests
- verifies that individual components work correctly together
- **integration strategies**:
    - **top-down** (test M1 first; write “simple/empty” procedures (stubs) for M2, M3, and M4; test M2 by writing stubs for M5 and M6, etc.)
    - **bottom-up** (test M5 first; write drivers to provide M5 the required input from M2; test M6, etc.)
    - **big-bang** (test all components (M1, M2, M3, M4, M5, M6, and M7) at once)
    - **sandwich** (combination of top-down and bottom-up strategies)

![alt text](<imgs/Screenshot 2025-01-20 alle 17.17.33.png>)

**System Testing**:
- after unit and integration testing
- often considered black-box testing
- involves the full development team
- **types**:
    - **functional and operational tests** --> check if functionalities meet the requirements
    - **performance tests** --> test non-functional requirements like wear, volume, configuration, compatibility, and regression
    - **acceptance tests** --> done with users or stakeholders to verify proper product functioning
    - **installation tests** --> ensure the system components are installed and function correctly

### Based on the Objective
**Objective** --> defines the purpose of the test

**Types of tests based on their objectives**:
- **regression testing** --> re-running tests to validate changes
- **functional testing** --> detect errors in the implementation
- **capacity and performance tests**:
    - **capacity** --> test with abnormal resource use
    - **performance** --> measure response times, disk, memory usage
- **resource usage (efficiency) testing** --> optimize resource use
- **security testing** --> verify protection mechanisms
- **user (usability) testing** --> ensure the interface is user-friendly
- **acceptance testing** --> validate the entire system with clients and stakeholders

## Unit Testing with JUnit
- testing frameworks --> xUnit
- xUnit for Java --> JUnit
- chosen for its wide acceptance and use
- open-source framework for writing test cases that can be executed and verified automatically
- set of Java classes that allows testing other classes written in Java using a black-box model

### Basic Elements of JUnit
- **Test cases** --> methods that execute methods from another class that is being tested
- **Test suites** --> collections of test cases that test functionally related classes

## Testing Process
- concepts integrated into a structured process
- **key aspects**:
    - **objective** --> guides the testing process
    - **management** --> coordinates tests at various levels
    - **documentation** --> includes test plans and design specifications (e.g., IEEE 830-1998)
    - **team structure** --> organizes internal/external team members
    - **process metrics** --> determines which metrics are used
    - **end of testing** --> decides when sufficient tests are done and the process is complete