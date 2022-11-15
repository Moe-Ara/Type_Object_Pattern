# Type_Object_Pattern
### Overview:
This is a small project that demonstrates how to implement/use the Type Object pattern in c++.
The theoretical part of the project is taken from [Robert Nystrom's Game Programming Patterns](http://gameprogrammingpatterns.com).
The Idea of this pattern is to create type objects and typed objects Each type object instance represents a different logical type. Each typed object stores a reference to the type object that describes its type.
It is actually very similar to the [Factory method pattern](https://en.wikipedia.org/wiki/Factory_method_pattern).

This pattern helps us avoid the drawbacks of inheritance.

To be more specific it helps us convert this
![http://gameprogrammingpatterns.com/type-object.html](/Resources/img_1.png)
Into this:
![http://gameprogrammingpatterns.com/type-object.html](/Resources/img.png)

Breed is then responsible for creating new Monsters based on specific input.

### Technical:

In directory `./include` you can find two header files that describe the relation between Monster and Breed class.
`Breed.h` holds all information about a breed of monsters, and it has a method to create monsters based on itself.
`Monster.h` holds reference to a breed and is can't be created outside of `breed.h`.

In directory `./src` you can find the implementation for both classes.

In `demo.cpp` you can find a `main` method that demonstrates how the patterns works. You can also find a method that parses Json and creates objects from Json objects. (For Json parsing, [cjson](https://github.com/DaveGamble/cJSON) Library was used).

The File [Monsters.json](/JsonFiles/Monsters.json) holds information about the objects that have to be created.
It gets read in the `main` method and is passed to another method to parse it.


As you can see, this program supports inheritance for the breeds of monsters, this means that we can create a new breed and inherit properties from its parent.
```json{
  {
  "Troll": {
    "health": 24,
    "attack": "Troll Attacking"
  },
  "Wizard": {
    "parent": "Troll",
    "health": 0,
    "attack": "Wizard Attacking"
  },
  "Archer": {
    "parent": "Troll",
    "health": 20,
    "attack": "Archer Attacking"
  },
  "Dragon": {
    "health": 500,
    "attack": "Dragon burns you"
  }
}
```
As you can see, `Wizard` and `Archer` inherit from `Troll` whereas `Dragon` and `Troll` have no parents.

#### output:
```shell
Troll: { health: 24, Attack: Troll Attacking }
Wizard: { health: 24, Attack: Wizard Attacking }
Archer: { health: 20, Attack: Archer Attacking }
Dragon: { health: 500, Attack: Dragon burns you }

Process finished with exit code 0
```
### Reasons:
- This Pattern allows non-technical users to create and/or modify objects fairly easily.
- It allows us to have a better software architecture 
- Easier than maintaining 100s of objects in the codebase

### TODOS:
- Replace all Raw pointers by smart pointers
- Make better Documentation
- Don't allow duplicating same breed

### Resources:
- [Robert Nystrom's Game Programming Patterns](http://gameprogrammingpatterns.com)
- [cjson](https://github.com/DaveGamble/cJSON)
