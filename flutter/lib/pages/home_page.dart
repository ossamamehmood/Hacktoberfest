import 'package:app/models/cart.dart';
import 'package:app/models/catalog.dart';
import 'package:app/pages/home_details.dart';
import 'package:app/utils/routes.dart';
import 'package:app/widgets/drawer.dart';
import 'package:flutter/cupertino.dart';

import 'dart:convert';
import 'package:velocity_x/velocity_x.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';




class  HomePage extends StatefulWidget {
  const HomePage({super.key});



  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {

@override
  void initState() {
    super.initState();
    loadData();
  }

  loadData() async {
   final catalogJson = await rootBundle.loadString("assets/files/catalog.json");
   final decodedData = jsonDecode(catalogJson);
    var productData = decodedData["products"];
    CatalogModel.items = List.from(productData).map<Item>((item) => Item.fromMap(item)).toList();
    setState(() {

    });
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(

      appBar: AppBar(

        backgroundColor: context.cardColor,
       title: const Text("Vimal Store", style: TextStyle(
           color: Color(0xffe7edfc),
           fontWeight: FontWeight.w900,
           fontSize: 30.0,
       ),),
      ),

      floatingActionButton: FloatingActionButton( onPressed: ()  => Navigator.pushNamed(context, MyRoutes.cartRoute),
        backgroundColor: const Color(0xff0e3b60),
        foregroundColor: Colors.white,
        child: const Icon(CupertinoIcons.cart),
      ),
      backgroundColor: context.cardColor,
         body: SafeArea(

           child: Container(
             padding: const EdgeInsets.symmetric( vertical : 12 ,horizontal: 32),
             child:   Column(

               crossAxisAlignment: CrossAxisAlignment.start,
               children: [

                 const  CatalogHeader(),
                 const CatalogList().py16().expand(),

             ],
           ),
         ),

        ),

      drawer: MyDrawer(),

    );

  }
}
class CatalogHeader extends StatelessWidget {
  const CatalogHeader({super.key});

  @override
  Widget build(BuildContext context) {
    return  const Column(
      crossAxisAlignment: CrossAxisAlignment.center,
      children: [

         SizedBox(
           height: 20.0,
         ),
        Text(" Most Selling Products",style: TextStyle(
            color: Color(0xffd0f8fc),
            fontWeight: FontWeight.w900,
           fontSize: 25
        ),),
        SizedBox(
          width: 10,
          height: 20,
        ),
      ],
    );
  }
}
class CatalogList extends StatelessWidget {
  const CatalogList({super.key});


  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      shrinkWrap: true,
      itemCount: CatalogModel.items.length,
      itemBuilder: (context , index){
        final catalog = CatalogModel.items[index];
        return InkWell(
            onTap: () => Navigator.push(context, MaterialPageRoute(builder: (context)=>HomeDetailPage(catalog: catalog),
            ),
            ),
            child: CatalogItem(catalog: catalog),
        );
      },
    );
  }
}
class CatalogItem extends StatelessWidget {
 final Item catalog;

  const CatalogItem({super.key, required this.catalog});

  @override
  Widget build(BuildContext context) {
    return VxBox(
    // width: 40,
    //   height: 40,
    //   color: Color(0xff041748),

      // padding: EdgeInsets.all(8),
      child: Row(
        children: [

          Hero(
              tag: Key(catalog.image),
              child: Image.network(catalog.image).box.roundedLg.color(const Color(0xfff3feff)).make().p20().px8()),

          Expanded(child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text(catalog.name, style: const TextStyle( color: Color(0xff34078d), fontSize: 15 , fontWeight: FontWeight.w900),),

           10.heightBox,
           ButtonBar(
             buttonPadding: Vx.mOnly(right: 8),
             alignment: MainAxisAlignment.spaceAround,
             children: [
               "₹${catalog.price}".text.bold.xl.make(),
             _AddToCart(catalog : catalog),
             ],
           )


            ],
          ))
        ],
      ),
    ).color(context.canvasColor).square(130).roundedLg.make().py16();
  }
}
class _AddToCart extends StatefulWidget {
 final Item catalog;
  const _AddToCart({super.key, required this.catalog});

  @override
  State<_AddToCart> createState() => _AddToCartState();
}

class _AddToCartState extends State<_AddToCart> {
  final _cart = CartModel();
  @override
  Widget build(BuildContext context) {
    bool isInCart = _cart.items.contains(widget.catalog) ?? false;
    return   ElevatedButton(
      onPressed:() {

        if (!isInCart) {
          isInCart = isInCart.toggle();
          final _catalog = CatalogModel();

          _cart.catalog = _catalog;
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
      child: isInCart ? Icon(Icons.plus_one_rounded)  : "Add To Cart".text.make(),
    );
  }
}
