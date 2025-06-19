`Bottom-Up Approach`-make smaller objects first and then larger objects
`Top-Down Approach`-make the larger objects first and then smaller objects

---

We're gonna use bottom-up approach for this question

### We'll first find how many objects are there

a.Menu Item-Code,name,price-ths class is also a modal class since it has variables and getters-setters and no functionality

1.Restaurant- id,name,address, Menu Items

```
a-1 has a "has a " relationship (restaurant has a menu)(
Composition Relationship-In an example of chair it has arms,seat,wheels, and these components can’t exist independently, thus they have a composition relationship, it is represented by a closed diamond.
)
```

Now, restaurants aren't fixed they can be added and deleted and to manage it we'll create another object
b. **_Restaurant Manager_** -performs CRUD operations on restaurants,can search restaurant based on location,has list of all the restaurants
Every manager class is a singelton class

```
b-1 is a "has-a" relationship but a restaurant can exist without a manager and a restaurant exists inside the restaurant manager(
    Aggregation Relationship-the main object acts as an aggregator,it acts as a container,like a room will contain sofa,chair,bed.It is stronger than a simple has-a relationship,since the connection is more complex,represented by diamond operator.
)
```

We don't want anyone to directly access the restaurant,the user should deal with the the restaurant manager which will deal with the restaurant

---

2.User(modal class)-id,name,address,cart(Every user has one cart)
c.Cart-restaurant,menu items,total(),addtocart(item),clear(),isEmpty().

```c-1-Simple Association Relation,One-to-One
c-a simple association,one-to-many relationship
c-2 Composition Relationship, cart can't exist without a user
```

`Integrating Payment`-Using Strategy Design Pattern
(
Strategy Design pattern defines a family of algorithm and then into separate classes so that they can be changed at run time
)
3.Payment Strategy-pay()
3.a. Netbanking-pay(){}
3.b. Credit Card-pay(){}
3.c. UPI-pay(){}

4. Order -id,restaurant,menu items,user,payment strategy,gettype(),--this will be a abstract class since gettype() is an abstract object
   4.a.Delivery Order-gettype()
   4.b.Pickup Order-gettype()
   `We're gonna make a order manager and order factory(from Factory Design Pattern)-we could've made restaurant factory also but we gave the functinality of restaurant creation to the manager itself`
5. Order Factory-createOrder()--it is an interface
   (
   5-4 has a 'has-a' relationship
   )
   5.a.NowOrderFactory-createorder(){}
   5.b.ScheduleLaterFactory-createorder(){}
   (
   5.a.and 5.b. can make both the type of orders
   )
6. Order Manager-orders,addorders()(
   one-to-many relationship between order and order manager
   6-4 has an aggregation relationship,
   singelton class
   )
7. Notification Service-(integrated from other parties)notify(order)(
   notification service has a order
   )
8. Tomato(name of the app)-this class is important because it is an orchaestrator,it deals with all the classes and gives the user a single point of contact 
