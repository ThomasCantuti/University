# Construction
**Good Software System comprends:**
- functionality
- maintainability
- readability
- standards
- performance

**Construction** = coding + testing and/or detailed design

**Coding** --> process of expressing a computer program in a programming language

**Construction** --> coding + verification + testing + debugging

**more important than how to program in a specific language:**
- analyzing the fundamentals of program construction
- describing the management of the construction process

## Construction Languages
**Construction languages** --> all possible forms of communication through which a human can specify to a computer an executable solution to a problem (part of "computer languages": query, specification, construction, etc.)

**Types of Construction Languages:**
- **Configuration Languages** --> tipically provided in text files, allow specifying how a particular software installation will be configured from a set of options (e.g. Linux configuration files, Apache server configuration, package.json, pom.xml, etc.)
- **Toolkit Languages** --> used to build applications from predefined blocks in toolboxes (blocks assembled through a graphical interface or a simple, custom language)
- **Programming Languages** --> more flexible, powerful, and widely used, implement the detailed design of the system, influence the software development process

### Programming Languages
**Programming Languages** --> composed of a vocabulary and grammatical rules for writing executable commands

**Classification:**
- **1GL (Machine languages)** --> binary codes processed by the machine (e.g. 00000 00000 00010 00000 00100 00000)
- **2GL (Assembly languages)** --> intermediate between machine language and high-level languages (e.g. PUSH EAX, MOV AX, 18H)
- **3GL (High-level languages)** --> facilitate communication between humans and computers (e.g. Fortran, Cobol, Basic, C, C++, Java)
- **4GL** --> focus on what should be done, often for database access (e.g. SQL, PowerBuilder)
- **5GL** --> related to artificial intelligence, define problems through constraints (e.g. Haskell, Prolog, Lisp, Mercury)

## Code Reusability
**code reusability** --> reuse previously created components and design new ones for reuse

**software library** --> controlled collection of software and related documentation designed to facilitate development, use, or maintenance of software (library elements should be as independent as possible from the domain)

**Objective:** Make them reusable in various types of software applications

**Advantages of using libraries:**
- pre-tested code
- optimized code
- covers most situations and cases
- more cost-effective, faster, and reliable than writing new code

**Disadvantages:**
- difficult to modify if output is not as expected
- requires time to understand how they work
- may pose security risks
- may have acquisition or usage costs
- may involve intellectual property issues

## Fundamental Principles of Software Construction
- **Minimize complexity**
- **Anticipate changes**
- **Build for verification**
- **Use standards**

### Minimizing Complexity
---
- divide the code into parts
- simplify development, comprehension, and modification
- **techinques to simplify code**:
    - Readability Techniques
    - Error Handling Management
    - Code Documentation
    - Code Tuning Techniques

**Readability Techniques:**
- **identifier names:** 
    - meaningful but short
    - uppercase for constants
    - verbs in infinitive and lowercase for methods
    - nouns in lowercase for attributes and local variables (and in some languages, global ones too)
    - nouns in uppercase for classes and structures
- **comments:**
    - code should be accompanied by comments
    - explain aspects or details not self-explanatory
- **code structuring:**
    - group statements related to behavior into paragraphs
    - proper indentation
    - method size limit: 1 page
    - line length limit (70–80 characters)
    - fixed indentation spaces (2–3 spaces)
    - do not mix spaces and tabs (prefer spaces)
    - separate sections with blank lines (don’t overuse)
- **expressions:**
    - use parentheses to avoid confusion
    - split long expressions into subexpressions (before operators or parentheses)
- **control statements layout:**
    - method start and end symbols should be placed on lines dedicated to that purpose
    - avoid blocks with only one line

**Error Handling Management:**
- modern programming languages use **Exception handling**
- **Exception** --> unexpected anomaly or error condition that occurs during program execution
- **error sources:**
    - division by zero
    - overflows or underflows
    - unexpected method or function arguments
    - array index out-of-bounds
    - file access errors
- **types of exceptions:**
    - **Synchronous:** occur at predictable times (e.g. opening and reading a file, accessing an array)
        - **Advantages:**
            - separates error handling code from the rest
            - allows propagating error handling up the call stack between methods
            - groups and classifies different error types
        - **Usage:** try – catch – throw
    - **Asynchronous:** outside of program control (e.g. key presses that abort a program or close a window)

**Code Documentation:**
- add inforation to the original code to explain what it does
- goal: explain why the code was written in that way, not just to translate its actions

**Code Tuning Techniques:**
- improve efficiency but require experience (not best way to improve program efficiency)
- **classification**:
    - **space rules (to save time):** increase data structure size to reduce access time
    - **time rules (to save space):** reduce data structure size, even if access time increases
    - **loop rules:** move code outside the loop or merge loops iterating over the same set
    - **logical rules:** reorder logical expressions or replace them with algebraically equivalent ones
    - **procedure rules:** convert recursive methods to iterative ones, exploit parallelism, etc.
    - **expression rules:** replace algebraic expressions with equivalent ones (e.g. trigonometric to sums and multiplications, ...)

### Anticipating Changes
---
- isolate the most unstable parts of the system (failures -> affect as few processes as possible)
- **Key points:** identify, separate, and isolate elements expected to change
- **Elements expected to change:**
    - business rules
    - hardware dependencies
    - application inputs and outputs
    - non-standard programming language extensions
    - design or construction challenges
    - state variables (use enumerated types)
    - data size limitations (flexible data structures)

### Building for Verification
---
- build software while identifying and fixing errors that may cause runtime failures
- **Techniques:**
    - code review and test to analyze and check parts of the system
    - organize code for automated testing (e.g. using xUnit frameworks)
    - limit the use of complex software structures (e.g. pointers, recursion)

### Using Standards
---
- **Standard** --> set of documented technical specifications
- ensure interoperability between products from different manufacturers
- **types of standards:**
    - **External:** published by national and international standardization bodies (ISO, IEEE, IETF, OMG, W3C, etc.)
        - **Examples:** ISO 9001 (quality system), IEEE 1008-1987 (unit testing), UML (OMG), HTML (W3C)
    - **Internal:** internal mandatory rules or recommendations for software construction within an organization
        - **Examples:** variable type prefixes, Java coding conventions, documentation structure, etc.

## Quality in Software Construction
**assertions** --> logical expressions that specify the state of a program or a set of conditions that variables in the program must meet at a specific point during execution
- **advantages**:
    - help build reliable software
    - provide systematic documentation
    - serve as a tool for software checking and debugging
- **behavior defined** with assertion through preconditions and postconditions:
    - **precodition** --> logical expression that defines properties that must be satisfied before invoking the code
    - **postcondition** --> defines properties the code must guarantee once it finishes execution

**invariants (another use of assertion)** --> logical expression that should always be true at a specific part of the program

**Performance Analysis**:
- **Profiling** --> monitoring and studying the behavior of a software component using data generated during execution
- **Detect performance issues** --> memory leaks or low execution speed
- **Memory leak** --> gradual loss of available memory due to a defect in the application
- **Performance analysis tools** --> information about a program’s behavior during execution

**Debugging** --> detect, locate and fix bugs in a program

**Techniques for Debugging:**
- **breakpoints** --> stop execution to observe the program’s state and results
- **watches** --> allow observation of variable values
- **step-by-step execution** --> run the program instruction by instruction to see how data changes
- **execution tracing** --> track which instructions are being executed and their sequence
- **desk checks** --> manually execute a process with a set of input data

**Debugging Rules** (Agans, 2002):
- understand the system (documentation)
- force the system to fail
- don’t think, just observe
- narrow the search
- modify only one thing at a time
- perform audits (log events during execution)
- check the obvious first
- ask for others’ opinions
- if it’s not fixed, the error might still exist (not reproducing the error doesn’t mean it’s fixed)

## Construction Management
depending on the software development method:
- coding
- coding + testing
- coding + testing and/or detailed design

**Construction Planning**:
- choose the construction method and language
- apply construction principles:
    - minimize complexity
    - anticipate changes
    - build to verify
    - use standards
- define the order of component creation and integration
- actions related to process quality
- assign tasks to project team members

**Construction Metrics**:
- **Artifacts and elements commonly measured:**
    - developed code
    - reused code
    - deleted code
    - code complexity
    - code inspection statistics
    - percentage of errors found and fixed