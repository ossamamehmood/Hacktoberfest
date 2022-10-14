
// function to find items starting with {{ and ending with }}
void main(List<String> args) {
  String str = "Hi {{1}} this is my name {{2}}";
  print(findString(str));
}

List<String> findString(String str) {
  List<String> items = [];
  RegExp exp = RegExp(r'{{([^]*?)}}');
  Iterable<RegExpMatch?> match = exp.allMatches(str);
  match.forEach((element) {
    for (var i = 0; i < element!.groupCount; i++) {
      items.add(element.group(i) ?? "");
    }
  });
  return items;
}
