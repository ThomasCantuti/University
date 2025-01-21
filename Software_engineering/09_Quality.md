# Quality
**software quality** --> how well a software meets the desired combination of attributes (reliability, usability, maintainability, performance, etc.)

**Product Quality Models**:
- McCall’s Quality Model
- Boehm’s Quality Model
- ISO/IEC 9126 Quality Model
- ISO/IEC 25000 Quality Model
- Others: Dromey, FURPS/FURPS+, IEEE 1061

## McCall’s Quality Model

![alt text](image.png)

**goal** --> align the quality perspectives of developers and users

Organized around three types of quality characteristics:
- **Quality Factors** --> how users perceive the software externally
- **Quality Criteria** --> how the software should be constructed internally from the developer’s perspective
- **Quality Metrics** --> how to control and measure the quality

Three perspectives:
- **Product Revision**:
    - product adaptability to changes
    - **factors**: maintainability, flexibility, and ease of evaluation
- **Product Transition**:
    - factors that describe the adaptability to different operating environments
    - **factors**: reusability, portability, and interoperability
- **Product Operation**:
    - factores that describe how well software performance functions and it meets specifications
    - **factors**: correctness, reliability, efficiency, integrity, and usability (usability relates to metrics for evaluating quality)

## Boëhm’s Quality Model
**goal** --> identify a number of quality characteristics for software

**First level** of hierarchy model (**high-level utilities**):
- **Utility as it is** --> current state of the software in terms of usability, reliability, and efficiency
- **Maintainability** --> ease of identifying what needs to be modified and how easy it is to make modifications or conduct tests
- **Portability** --> ease of using the software in a new environment

**Second level** of hierarchy model (**quality factors**):
- **Reliability (utility as it is)** --> absence of bugs
- **Efficiency (utility as it is)** --> minimum resource usage during correct system operation
- **Usability (utility as it is)** --> ease of use of the software (related to human engineering and ergonomics)
- **Ease of evaluation (maintainability)** --> validation of the established requirements
- **Understandability (maintainability)** --> ease of understanding the purpose and structure of the software
- **Flexibility (maintainability)** --> ease of modifying the software before changes in requirements or the appearance of new ones
- **Portability (portability)** --> ease of using the software in new environments

## ISO/IEC 25000 Quality Model (ISO/IEC 9126 model update)
SQuaRE Project (SQuaRE - System and Software Quality Requirements and Evaluation): Requirements and Evaluation of Software Product Quality

![alt text](<imgs/Screenshot 2025-01-21 alle 13.08.20.png>)

![alt text](<imgs/Screenshot 2025-01-21 alle 13.08.39.png>)

![alt text](<imgs/Screenshot 2025-01-21 alle 13.08.59.png>)

## Process Quality
**Focus** --> ensure all production steps meet quality standards (good process -> better product quality)

**Process Quality Models**:
- CMMI
- SPICE
- ISO 9000 family of standards
- ITIL

### CMMI (Capability Maturity Model Integration - CMM updated version)
- framework to organize and prioritize activities (guide to outline effective process characteristics)
- includes best practices to improve how an organization works (use technology and tools)
- maturity model --> describes the balance, experience, and formality of an organization
- organizations can “mature” by achieving higher maturity levels:
    - **lower levels** --> organizations without repeatable processes, where much of the work is done on an ad-hoc basis
    - **higher levels** --> organizations with defined, repeatable processes that apply metrics for continuous improvement
- CMMI certifies an organization’s process quality level, measuring process in two ways:
    - **stage representation**
    - **continuous representation**

### ISO 9000 Family of Standards
- **ISO 9000** --> set of standards for quality management systems (do not describe how to execute processes that ensure quality)
- **ISO 9000:2015** --> provides basic principles and vocabulary for quality management systems
- **ISO 9001:2015** --> specifies the minimum requirements for an efficient quality management system (most important standard, setting a baseline for all organizations to meet)
- **ISO 9004:2015** --> focuses on improving performance in a quality management system (continuous improvement)
- define requirements that an organization must meet for a good quality management system (no what organizations must do achieve)

### ITIL (Information Technology Infrastructure Library)
- set of best practice documents to facilitate implementation
- ITIL consists of five volumes:
    1. Service Strategy
    2. Service Design
    3. Service Transition
    4. Service Operation
    5. Continual Service Improvement

![alt text](<imgs/Screenshot 2025-01-21 alle 13.41.42.png>)