# Maintenance
**Focus** --> modifying or changing the software (necessary to fully understand what needs to be changed beforehand)

## Fundamental Concepts
**software maintenance** --> modification of a software product after delivery to **fix bugs**, **improve performance** or other attributes, or to **adapt the product** to a modified environment (sometimes can begin before product delivery)

- **pre-delivery** --> planning for post-delivery operations, support planning, and logistics
- **post-delivery** --> modifying the software, training users, initiating technical support, and customer service

**maintainability** --> system or component to correct faults, improve performance, or adapt to changes in the environment (greater maintainability = lower cost)

**key factors impacting maintainability**:
- **development process** --> maintainability should be part of the development process
- **documentation**
- **understanding of programs** --> minimize software complexity to avoid misinterpretation of functionality

**maintainability** --> a combination of **repairability** and **flexibility**
- **repairability** --> fix bugs with limited and reasonable effort
- **flexibility** --> make changes to meet new requirements

## Software Maintenance Practice
- **effort invested in maintenance** --> high, ranging from 50% to 80%, depending on the system and the study conducted
- **differences from other types of products**:
  - does not physically deteriorate with use or over time
  - structure can deteriorate with each change --> **design erosion**

**Software Evolution** --> activities that generate the new version of software from a previous one (part of the maintenance process)

## Maintenance Process

![alt text](<imgs/Screenshot 2025-01-21 alle 10.55.39.png>)

## Techniques for Software Maintenance
- **Reverse Engineering**
    - looking at a finished product and figuring out how it works then breaking it down to understand its parts and how they connect
    - **Example**: taking existing code and creating a diagram that shows how the classes (or parts of the code) are related

- **Reengineering**
    - changing parts of the software, using reverse engineering to understand the system and then improving it with new tools
    - **Example**: if there are methods (functions) in the code that affect multiple parts of the system, the goal is to redesign them and show how they connect using a new diagram
- **Refactoring**
    - improving the code’s structure without changing what it does (cleaning up the code so it’s simpler and easier to understand)
    - **Example**: renaming methods to make them clearer or breaking down large classes into smaller or easier-to-manage ones

## Maintenance Metrics
- **Product Metrics**:
    - software maturity index
    - documentation quality metrics
    - design quality metrics
    - maintainability index
- **Process Metrics**:
    - product development time
    - number and type of resources used
    - process cost