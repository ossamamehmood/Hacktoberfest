import 'package:app/models/catalog.dart';

class CartModel{
  static final cartModel = CartModel._internal();
  CartModel._internal();
  factory CartModel() => cartModel;



// catalog fields
  late CatalogModel _catalog;
// collection of id to store id for each
  final List<int> _itemIds = [];
// get catalog
  CatalogModel get catalog => _catalog;
  set catalog(CatalogModel newCatalog){
    _catalog = newCatalog;
  }
// get items in cart
  List<Item> get items => _itemIds.map((id)=> _catalog.getById(id)).toList();


  // Get Total Price

num get totalPrice => items.fold(0, (total , current) => total + current.price);

// Add item
void add(Item item){
  _itemIds.add(item.id);
}
// Remove item
  void remove(Item item){
    _itemIds.remove(item.id);
  }
}


