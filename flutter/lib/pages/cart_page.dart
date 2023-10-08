

import 'dart:io';

import 'package:app/models/cart.dart';
import 'package:flutter/material.dart';
import 'package:velocity_x/velocity_x.dart';
class CartPage extends StatelessWidget {
  const CartPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: context.cardColor,
      appBar: AppBar(

        backgroundColor: Colors.transparent,
        title: "Cart".text.xl3.cyan50.center.make(),
      ),
      body: Column(
        children: [
          _CartList().p32().expand(),
          Divider(),
          _CartTotal(),
        ],
      ),
    );
  }
}
class _CartTotal extends StatelessWidget {


  @override
  Widget build(BuildContext context) {
    final _cart = CartModel();
    return SizedBox(
      height: 100,
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        children: [
          "\₹${_cart.totalPrice}".text.xl3.color(context.theme.hintColor).make(),
          40.widthBox,
          ElevatedButton( onPressed: (){
    
        },
              style: ButtonStyle(
                backgroundColor: MaterialStateProperty.all(context.canvasColor),
              ),
              child: "Buy Now".text.gray900.make(),
          )

        ],
      ),
    );
  }
}


   class _CartList extends StatefulWidget {
  const _CartList({super.key});

  @override
  State<_CartList> createState() => _CartListState();
}

class _CartListState extends State<_CartList> {
 final _cart = CartModel();
  @override
  Widget build(BuildContext context) {
    if (_cart.items.isEmpty) {
      return "Kuch to order Kr dijiye Sir 🙏🏼".text.xl4.white.center.makeCentered();
    } else {
      return ListView.builder(
        itemCount: _cart.items?.length,
        itemBuilder: (context , index) =>  ListTile(
          leading: IconButton(
            icon: Icon(Icons.add , color: Colors.white,),
            onPressed: () {
              _cart.add(_cart.items[index]);
              setState(() {});
            },
          ),
          trailing: IconButton(
            icon: Icon(Icons.remove_circle , color: Colors.white,),
            onPressed: () {
              _cart.remove(_cart.items[index]);
              setState(() {});
            },

          ),

          title: _cart.items[index].desc.text.white.make(),
        ).color(context.theme.backgroundColor),

    );
    }
  }
}

