import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:harshjain_102103432/voterpage.dart';

void main()=>runApp(const MaterialApp(
  home: HomePage(),
));

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {

  Future<FirebaseApp> initializeFirebase() async{
    FirebaseApp firebaseApp=await Firebase.initializeApp();
    return firebaseApp;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body:FutureBuilder(
        future: initializeFirebase(),
        builder:(context,snapshot)
          {
            if(snapshot.connectionState==ConnectionState.done){
              return const LoginPage();
            }
            return const Center(
              child: CircularProgressIndicator(),
            );
          },
      ),
    );
  }
}


class LoginPage extends StatefulWidget {
  const LoginPage({Key? key}) : super(key: key);

  @override
  _LoginPageState createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {

  final emailc=TextEditingController();
  final passc=TextEditingController();

  bool _isObscure = true;

   Future<User?>loginUsingEmailPassword({required String email, required String password,required BuildContext context})async{
    FirebaseAuth auth=FirebaseAuth.instance;
    User?user;
    try{
      UserCredential userCredential=await auth.signInWithEmailAndPassword(email:email,password:password);
      user=userCredential.user;
  }on FirebaseAuthException catch (e){
      if(e.code=="user not found"){
        const Text("No user for this email");
      }
    }

    return user;
}
  @override
  Widget build(BuildContext context) {
    return(
    Scaffold(
      body:
      SafeArea(
        child: Padding(
          padding: const EdgeInsets.all(15),
          child: SingleChildScrollView(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.stretch,
              children: [

                Row(
                  children: [
                    Container(
                      child: const Image(image: AssetImage('assets/images/tl.jpg'), height: 110,width: 110,),
                    ),
                    Container(
                      margin: const EdgeInsets.fromLTRB(15, 0, 0, 0),
                      child: const Text("HarshJain(102103432)",style: TextStyle(fontSize: 10),),
                    ),
                    Container(
                      margin: const EdgeInsets.fromLTRB(0, 0, 0, 0),
                      child: const Image(image: AssetImage('assets/images/tr.jpg'), height: 110,width: 110,),
                    ),
                  ],
                ),



                Container(
                  padding: const EdgeInsets.fromLTRB(95, 60, 0,0),
                  child: const Text(
                      "WELCOME!",
                    style: TextStyle(
                      fontWeight: FontWeight.bold,
                      fontSize: 30,
                    ),
                  ),
                ),

                const SizedBox(height: 50,),


                Container(
                  child: const Text(
                    "Login :",
                    style: const TextStyle(
                      fontWeight: FontWeight.bold,
                      fontSize: 20,
                    ),
                  ),
                ),

                const SizedBox(height: 30),


                TextField(
                  controller: emailc,
                  keyboardType: TextInputType.emailAddress,
                  decoration: const InputDecoration(
                    hintText: "Enter email",
                    prefixIcon: Icon(Icons.mail_rounded,color: Colors.black,)
                  ),
                ),

                const SizedBox(height: 30),


                TextField(
                  controller: passc,
                    obscureText: _isObscure,
                  decoration: InputDecoration(
                      hintText: "Enter password",
                      prefixIcon: const Icon(Icons.lock,color: Colors.black,),
                    suffixIcon: IconButton(

                      icon: Icon(
                          _isObscure ? Icons.visibility_off : Icons.visibility),
                          onPressed: (){

                            setState((){
                              _isObscure = !_isObscure;
                            });
                          },
                      ),
                    ),
                  ),

                const SizedBox(height:50),


                ElevatedButton(
                    onPressed: ()async{
                      User?user=await loginUsingEmailPassword(email: emailc.text, password: passc.text, context: context);
                      print(user);
                      if(user!=null)
                        {
                          Navigator.of(context).push(MaterialPageRoute(builder: (context)=>const Home()));
                        }
                    },
                    child: const Text("Login"),
                ),

               
                    Row(
                      children: [
                        Container(
                            margin: const EdgeInsets.fromLTRB(0,70,0,0),
                            child: const Image(image: AssetImage('assets/images/bl.jpg'), height: 110,width: 110,)
                        ),
                         Container(
                          margin: const EdgeInsets.fromLTRB(130,70,0,0),
                          child: const Image(image: const AssetImage('assets/images/br.jpg'), height: 110,width: 110,),
                        ),

                      ],
                    ),

              ],
            ),
          ),
        ),
      ),
    )
    );
  }
}



