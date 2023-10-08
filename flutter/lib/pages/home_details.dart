import 'package:app/models/catalog.dart';
import 'package:app/utils/routes.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:velocity_x/velocity_x.dart';

import '../widgets/home_widgets/add_to_cart.dart';



class HomeDetailPage extends StatelessWidget {
final Item catalog;

  const HomeDetailPage({super.key, required this.catalog});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        floatingActionButton: FloatingActionButton(  onPressed: ()  => Navigator.pushNamed(context, MyRoutes.cartRoute),
          backgroundColor: const Color(0xff7bb6ae),
          child: const Icon(CupertinoIcons.cart),
        ),
      appBar: AppBar(
        foregroundColor: const Color(0xff869cad),
        title: "back".text.xl3.bold.make(),
        backgroundColor: Colors.transparent,
      ),
      bottomNavigationBar:

      Container(
        color: const Color(0xffaae5de),
        child: ButtonBar(

          buttonPadding: Vx.mOnly(right: 8),
          alignment: MainAxisAlignment.spaceAround,
          children: [
            "₹${catalog.price}".text.bold.xl4.purple800.make(),

            AddToCart(
                catalog : catalog
            ),
          ],
        ).p24(),
      ),
      backgroundColor: context.canvasColor,
      body: SafeArea(
        bottom: false,

        child: Center(

          child: Column(

            children: [

              Hero(
                tag: Key(catalog.image),
                  child: Image.network(catalog.image).box.roundedLg.make()).p32(),
              //
              // Hero(
              //     tag: Key(catalog.img),
              //     child: Image.network(catalog.image).box.roundedLg.make()).p32(),
              Expanded(child:
                VxArc(
                height: 20.0,

                edge: VxEdge.top,
                arcType: VxArcType.convey,

                   child: Container(
                     width: context.screenWidth,

                      color: context.cardColor,
                    child: Column(
                      children: [
                        const SizedBox(
                          height: 20,
                        ),
                       Text(catalog.name , style: const TextStyle( color: Color(
                           0xffb0d3fc), fontSize: 35 , fontWeight: FontWeight.w900),),


                        Text(catalog.desc, style: const TextStyle( color: Color(0xfff1edfa), fontSize: 25 , fontWeight: FontWeight.w900),),



                      ],
                    ).py32().px16()

                ),
              ))



            ],
          )
        ),
      )
    );
  }
}
