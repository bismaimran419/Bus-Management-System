Bus Management System
A console-based terminal application engineered in C++ utilizing core Object-Oriented Programming (OOP) paradigms. The system provides a scalable solution for transit tracking, seat reservation, and fleet administration through dedicated administrative and customer portals.

Key Features
Administrative Portal
Fleet Management: Full operations to add, modify, or decommission buses within the network.

Route and Schedule Optimization: Define transit paths, map specific buses to active routes, and update departure schedules.

Data Monitoring: Real-time tracking of overall seat occupancy and passenger logs.

Passenger Portal
Dynamic Route Inquiry: Instantly query active routes to verify destinations, bus assignments, and schedules.

Automated Ticketing Engine: Secure seat reservation matrix with an instant cancellation workflow that dynamically updates inventory.

Receipt Generation: Generates a structured digital ticket displaying passenger metrics, seat coordinates, fare calculation, and route details.

Technical Architecture and OOP Implementation
This system serves as a practical demonstration of clean architecture and software engineering principles:

Encapsulation: Restricts direct data modification by wrapping entity states (Bus, Passenger, Ticket) within robust class interfaces.

Inheritance and Abstraction: Implements a modular user model separating administrative privileges from standard customer operations while hiding complex backend menu logic.

Polymorphism: Leverages method overriding or overloading for dynamic interface rendering and action handling.

Memory Management: Efficient handling of arrays or pointers to maintain persistent seat configurations.
