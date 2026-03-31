# STRUKDAT_MiniProject_Bakery_System
Lina Fatima Azzahra Badr 5025251168

You are in-charge of running a popular walk-in bakery. The bakery can take n amount of orders at a time, with a maximum of 20 orders. You need to process customer orders in a way where customers who order "macarons" and "bread" will always be prioritized regardless of order number, and orders for other baked goods are served as soon as possible after the macarons and after the bread. The served goods are guaranteed to be fresh out of the oven.

Use a DEQUE for macarons.
Use a QUEUE for bread.
Use a STACK for non-macarons.

The serving hierarchy is macarons > bread > other.

Each order has:
   - An order number (int 1-99)
   - A pastry name (string, 1-100 characters, may contain spaces)

   Orders for macarons are always prioritized.
   If the macaron order is even, insert at the front
   If the macaron order is odd, insert at the back

   All orders are served as early as possible whilst sticking to the stated hierarchy.

   COMMANDS
      ORDER {order_number} {pastry_name}
      SERVE
      CANCEL {number}

    Sample Input 1:
      9
      ORDER 77 creme brulee
      ORDER 12 pie
      ORDER 46 macarons
      ORDER 23 macarons
      CANCEL 12
      SERVE
      SERVE
      SERVE
      SERVE

      Sample Output 1:
      macarons 46 served!
      macarons 23 served!
      creme brulee 77 served!
      no orders to serve!
