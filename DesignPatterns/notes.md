suppose in our application we have to simulate robots.

we make robot class

add features like walk, talk and projection(which is a virtual method because every robot looks a bit different)

let’s say only 2 types of robots exist -

1. companion robot
2. worker robot

now a new type of robot is made

1. sparrow robot-this robot has an added feature of flying and thus a new method called fly

now suppose new robots are added like crow, pigeon all of them have the feature to fly, thus we have to make a separate method

called fly in each of them which has the same code as fly method of sparrow robot

this breaks a very simple dry principle

DRY

and if we add fly method to the parent robot class the robots which don’t fly also can have the functionality to fly

thus we’ll increase the hierachy and create a child class known as flyable robot which will act as a Parent class which has the fly method defined init [we’re entering a slippery slope]

but now suppose we add a robot which flies in another way than the parent class and we add other robots which flies in ways different
{look at screenshot}

> `the solution to inheritance is not more inheritance`

<aside>
🖥️

strategy design pattern defines a family of algorithm and then into separate classes so that they can be changed at run time

</aside>

{look at ss}

robot class should have a has-a relatioship with talkable,walkable,flyable

this means the robot class is not using inheritance but composition

{look at ss which has refrences of talkable,etc, passed through it}

real world factory is where products are created,and in factory design pattern factory is the class whose objects are created

from the example from strategy design pattern,we have robot class with multiple algroithms like talkable,etc. .These algroithms would be passed dynamically to the robot class at run time

[the whole concept of object creation is handled somewhere else-dependency injections]

The whole motto of this point is to seperate our business logic from our object creation

this pattern says we’ll create a different class who’s whole point is to create object

3 TYPES OF FACTORIES

-Simple Factory-not a design pattern but a design principle

-Factory Method

-Abstract Factory Method

## Simple Factory:

<aside>
🖥️

a factory class that decides which concrete class to instantiate

</aside>

suppose we have an abstract class burger with a virtual function prepare we create three children of it basic, standard and premium now we want to make a factory which asks from the user which type of burger he wants and it takes an input and creates an object of the same class as the input

{code from ss }

## Factory Method:

expanding on the example taken, if there exists 2 factories singh and king and suppose singh burger makes the three kinds of burgers and the king makes healthier options like wheat version of the singh’s burgers now the two burger factories are the children of the burger factory,we add new burger classes and override the prepare method singh burger having access to only the burgers it makes and king burger to the ones it makes.

in this case also burger factory has a burger

## Abstract Factory Method:

in this method one factory is responsible for making more than one product

## Usage

in notification system class, we can send sms ,push,email,

# Singleton Design Pattern

most easy and useful

2 types of memory

1.heap-non primitive data types like custom classes etc.

1. stack-it stores all types of non primitive data type-int,char,bool

static methods
this is a very specific use case design pattern,

it is used when there are two objects and one object wants to know whenever the other object wants to change

Polling-whenever the observer object keeps asking the observable object if it’s value has changed at regular intervals of very small time duration

## DEFINITION

defines a one to many relationship bw objects so that when one object changes states,all of its dependants are notified and updated automatically
