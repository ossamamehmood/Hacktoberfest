import 'package:app/models/catalog.dart';
import 'package:app/pages/home_details.dart';
import 'package:app/utils/routes.dart';
import 'package:app/widgets/drawer.dart';
import 'package:flutter/cupertino.dart';

import 'dart:convert';
import 'package:velocity_x/velocity_x.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';




class shopPage extends StatefulWidget {


  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<shopPage> {

  @override
  void initState() {
    super.initState();
    loadData();
  }

  loadData() async {
    final catalogJson = await rootBundle.loadString(
        "assets/files/catalogs.json");
    final decodedData = jsonDecode(catalogJson);
    var productData = decodedData["products"];
    CatalogModel.items =
        List.from(productData).map<Item>((item) => Item.fromMap(item)).toList();
    setState(() {

    });
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      backgroundColor: context.cardColor,
        appBar: AppBar(
          backgroundColor: context.cardColor,
          foregroundColor: Color(0xffd7dff3),
          title: "Vimal Store".text.make(),
        ),
    body:
    Padding(
    padding: const EdgeInsets.all(17.0),
    child: GridView.builder(
    gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
    crossAxisCount: 2,
    mainAxisSpacing: 16,
    crossAxisSpacing: 12,
    ),
    itemBuilder: (context , index){
    final item = CatalogModel.items[index];
    return InkWell(
        onTap: () => Navigator.push(context, MaterialPageRoute(builder: (context)=>HomeDetailPage(catalog: item),
    ),),
      child: Card
      (
      clipBehavior: Clip.antiAlias,
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(20)),

      child: GridTile(



          child: Image.network(item.image).box.roundedLg.make().p32().py16(),


         footer: Container(
            child: Text( item.name ,style: TextStyle( color: Colors.black45),),
      padding: const EdgeInsets.all(12),
      decoration: BoxDecoration(
      color: context.canvasColor,
      ),

      ),


      ).color(context.theme.hintColor)


      ),
    );

    },
    itemCount: CatalogModel.items.length,
    )
    ),
    // Text(context.runtimeType.toString()),
    drawer: MyDrawer(),

     );
  }
}

