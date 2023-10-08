class CatalogModel {
  static final catModel = CatalogModel._internal();
  CatalogModel._internal();
  factory CatalogModel() => catModel;
  static List<Item> items =[ ];
   Item getById(int id) => items.firstWhere((element) => element.id == id, orElse: null);
   Item getByPosition(int pos) => items[pos];
}

class Item{
  final int id;
  final String name;
  final String desc;
  final num price;
  final String color;
  final String image;
  final String img;

  Item({required this.id, required this.name, required this.desc, required this.price, required this.color, required this.image, required this.img});

  factory Item.fromMap(Map<String,dynamic> map){
    return  Item(
          id: map["id"],
          name: map["name"],
          desc: map["desc"],
          price: map["price"],
          color: map["color"],
          image: map["image"],
          img: map["img"]
      );
     }
     toMap() => {
       "id": id,
       "name": name,
       "desc": desc,
       "price": price,
       "color": color,
       "image": image,
       "img": img,
     };
}
