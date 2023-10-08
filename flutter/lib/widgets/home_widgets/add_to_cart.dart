
import 'package:app/models/cart.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:velocity_x/velocity_x.dart';

import '../../models/catalog.dart';

class AddToCart extends StatefulWidget {

  final Item catalog;
   AddToCart({
    super.key,
    required this.catalog});

  @override
  State<AddToCart> createState() => _AddToCartState();
}

class _AddToCartState extends State<AddToCart> {
  final _cart = CartModel();
  @override
  Widget build(BuildContext context) {


    bool isInCart = _cart.items.contains(widget.catalog) ?? false;

    return
      ElevatedButton(
      onPressed:() {

        if (!isInCart) {
          isInCart = isInCart.toggle();
         _cart.add(widget.catalog);
          setState(() {});
        }

      },
      style: ButtonStyle(
          backgroundColor: MaterialStateProperty.all(
              const Color(0xff124bb4)
          ),
          shape: MaterialStateProperty.all(const StadiumBorder())

      ),
      child: isInCart ? const Icon(Icons.done)  : Icon(CupertinoIcons.cart_fill_badge_plus),
    );
  }
}
