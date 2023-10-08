
import 'package:app/models/catalog.dart';
import 'package:flutter/material.dart';

class ItemWidget extends StatelessWidget {
final Item item;

  const ItemWidget({super.key, required this.item})
      : assert(item != null);

  @override
  Widget build(BuildContext context) {
    return Card(
      child: ListTile(
        onTap: () {
          print("${item.name} pressed");
        },
        leading: Image.network(item.image),
        title: Text(item.name),
        subtitle: Text(item.desc),
         tileColor: Color(0xffdee3ee),
        textColor: Color(0xff041748),
        trailing: Text("\₹${item.price}", style: TextStyle(
          fontSize: 20.0,
          fontWeight: FontWeight.bold,
          color: Color(0xff041748),
        ),),
      ),
    );
  }
}
