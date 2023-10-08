
import 'package:app/utils/routes.dart';
import 'package:flutter/material.dart';
import 'package:velocity_x/velocity_x.dart';

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  String name = "";
  bool changeButton = false;
  final _formKey = GlobalKey<FormState>();

  moveToHome(BuildContext context) async {
    if(_formKey.currentState!.validate()) {


    setState(() {
      changeButton = true;
    });

    await Future.delayed(const Duration(seconds: 2));
    await Navigator.pushNamed(context, MyRoutes.homeRoute);
    setState(() {
      changeButton = false;
    });
  }
  }



  @override
  Widget build(BuildContext context) {
    return Material(
      color: context.canvasColor,
      child: Center(
        child: Form(
          key: _formKey,
          child: Column(
            children: [
              const SizedBox(height: 50.0,),
              const Text("Sign-In to Vimal Store",
              style: TextStyle(
                fontSize: 25,
                fontWeight: FontWeight.bold,
                color: Colors.black,
              ),
              ),
              const SizedBox(height: 5.0,),
              Image.asset("assets/images/logo.png",
              fit: BoxFit.contain,
              ),

              Text("Welcome to Vimal Store🙏🏼\n                    $name ",
              style: const  TextStyle(
                fontSize: 30,
                fontWeight: FontWeight.bold,
                color: Color(0xffc9a20c),
              ),),

             Padding(padding: const EdgeInsets.symmetric(vertical:13.0, horizontal: 27.0),
              child:  Column(
               children: [
                 TextFormField(

                   decoration: const  InputDecoration(

                     hintText: " Enter Username",

                     labelText: " Username",

                   ),
                   validator: (value){
                     if(value!.isNotEmpty) {
                       return null;
                       
                     }

                     return " Username is empty";

                   },
                   onChanged: (value){
                     name = value;
                     setState(() {});
                   },

                 ).color(context.theme.backgroundColor).cornerRadius(12).wFull(context).px32(),
                 SizedBox(height: 10,),
                 TextFormField(

                   obscureText: true,
                   decoration: const InputDecoration(

                     hintText: " Enter Password",
                     labelText: " Password",
                   ),
                   validator: (value){
                     if(value!.isEmpty) {
                       return " Password is empty";
                     }
                     else if(value.length < 6){
                       return " Password Length Should be more than 6";
                     }
                     else{
                       return null;

                     }


                   },
                 ).color(context.theme.backgroundColor).cornerRadius(12).wFull(context).px32().py16(),
               ],
             ),
             ),
              const SizedBox(height: 20.0,),

              Material(
                  color: const Color(0xff064673),
                  borderRadius: BorderRadius.circular(changeButton?100 : 20),

                child: InkWell(
                  onTap: () => moveToHome(context),
                 child: AnimatedContainer(
                   duration: const Duration(seconds: 1),
                   width: changeButton?50 : 150,
                   height: 50,
                   alignment: Alignment.center,
                   child: changeButton? const Icon(Icons.done, color: Colors.white,) :
                   const Text(
                     "Login",
                     style: TextStyle(
                       color: Colors.white,
                       fontWeight: FontWeight.bold,
                       fontSize: 18,
                     ),
                   ),
                   // decoration: BoxDecoration(
                   //   color: Colors.indigoAccent,
                   //   borderRadius: BorderRadius.circular(changeButton?50 : 20)
                   // ),
                 ),

                ),
              )



              // ElevatedButton(onPressed: () {
              //   Navigator.pushNamed(context, MyRoutes.homeRoute);
              // },
              //   child: Text("Sign-In", style: TextStyle(
              //   fontSize: 18,
              //   color: Colors.white70,
              //   fontWeight: FontWeight.w900,
              // ),), style: TextButton.styleFrom(minimumSize: Size(180, 50)),
              // )
            ],
          ),
        )
      ),
    );
  }
}
