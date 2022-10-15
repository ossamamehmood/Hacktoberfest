class CorePage extends StatefulWidget {
  const CorePage({Key? key}) : super(key: key);

  @override
  _CorePageState createState() => _CorePageState();
}

class _CorePageState extends State<CorePage> {

  int _currentindex = 0;
  final screenList = [
    HomePage(),
    ProfilePage(),
    NotificationPage(),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      floatingActionButton: 
          FloatingActionButton(
              tooltip: "Add Art",
              onPressed: () {},
              child: Icon(
                Icons.add,
              ),
            ),
        
      floatingActionButtonLocation:
          FloatingActionButtonLocation.miniCenterDocked,
      body:  screenList[_currentindex],
      bottomNavigationBar: BottomAppBar(
        color: Colors.pink,
        clipBehavior: Clip.antiAliasWithSaveLayer,
        notchMargin: 6,
        shape: const CircularNotchedRectangle(),
        child: BottomNavigationBar(
          // backgroundColor: Colors.grey[50],
          showSelectedLabels: true,
          iconSize: 20,
          selectedItemColor: Colors.black,
          showUnselectedLabels: true,
          elevation: 20,
          currentIndex: _currentindex,
          type: BottomNavigationBarType.fixed,
          items: const [
            BottomNavigationBarItem(
              activeIcon: Icon(Icons.home_rounded),
              icon: Icon(Icons.home_outlined),
              label: "Home",
            ),
           
            BottomNavigationBarItem(
              activeIcon: Icon(null),
              icon: Icon(null),
              label: "Publish",
            ),
            BottomNavigationBarItem(
              activeIcon: Icon(Icons.notifications_rounded),
              icon: Icon(Icons.notifications_outlined),
              label: "Notifications",
            ),
          ],
          onTap: (index) {
            setState(() {
              _currentindex = index;
            });
          },
        ),
      ),
    );
  }
}
