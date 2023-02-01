# [Design Pattern](https://www.tutorialspoint.com/design_pattern/abstract_factory_pattern.htm)

- Design Pattern
    - Creational
    - Structural
    - Behavioral

## Creational Pattern
- Factory
    - Message object based on type provider
    - Provider based on string rectangle, cricle
- Abstract Factory
    - Factory Provider
    - Get two factory rounded and normal
- Singleton
    - Used it
- Builder pattern
    - Meal Builder, packing, meal, provider
- Prototype
    - Creating duplicate object from cache by cloning


## Structural
- Adapter Pattern
    - Interface diiferent objects
    - Audio Play vs Complex Media Play
- Bridge Pattern
    - This pattern decouples implementation class and abstract class by providing a bridge structure between them.
    - For circle, customized draw API as interface
- Composite Pattern
    - Composite pattern is used where we need to treat a group of objects in similar way as a single object.
    - Employee holding Employee
- Decorator Pattern
    - Decorator pattern allows a user to add new functionality to an existing object without altering its structure
    - Just a wrapper around abstract class to add certain functionality
- Facade Pattern
    - Facade pattern hides the complexities of the system and provides an interface to the client using which the client can access the system.
    - Prebuilt object creation
- Flyweight Pattern
    - Flyweight pattern is primarily used to reduce the number of objects created and to decrease memory footprint and increase performance.
    - Object caching based on a key, create if not there.
- Proxy Pattern
    - In proxy pattern, a class represents functionality of another class.
- Filter Pattern
    - Implement filter interface with and or on list objects

## Behavioural Pattern
- Chain of Responsibility Pattern
    - As the name suggests, the chain of responsibility pattern creates a chain of receiver objects for a request. This pattern decouples sender and receiver of a request based on type of request.
    - Logger file, console, error
- Observer Pattern
    - Observer as constructor
- Interpreter Pattern
    - Expression checking
- Command Pattern
    - Stock Buy Sell through broker
- Iterator Pattern
    - Iterating over elements
- Mediator Pattern
    - Inside object communication with other objects
- Memento Pattern
    - Memento pattern is used to restore state of an object to a previous state. 
    - Memento pattern uses three actor classes. Memento contains state of an object to be restored. Originator creates and stores states in Memento objects and Caretaker object is responsible to restore object state from Memento.
- State Pattern
    - In State pattern a class behavior changes based on its state
    - A moving object taking its state as action executes
- Template Method
    -In Template pattern, an abstract class exposes defined way(s)/template(s) to execute its methods. Its subclasses can override the method implementation as per need but the invocation is to be in the same way as defined by an abstract class.
    - GamePlay
- Strategy Pattern
    - Operation as context, then execute with same object, like bridge pattern
- Visitor Pattern
    - Computer Visitor

- Business Delegate Pattern
- Composite Entity Pattern
    - Depenant object handle
- Data Access Object Pattern
    - DAO
- Intercepting filter
    - The intercepting filter design pattern is used when we want to do some pre-processing / post-processing with request or response of the application
    
Specification Pattern
Rules Pattern
Service Locator Pattern
Repository Pattern
- Null Object Pattern
    - Null object case handle
Lazy Load Pattern
Event Aggregator