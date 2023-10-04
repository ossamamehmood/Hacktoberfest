class Constructor {
    public static void main(String[] args) {
        Faltu faltu = new Faltu(34);
        System.out.println(faltu.i+" "+faltu.j );
    }
}


class Faltu{
   int i;
   int j;
   static String ceo;
   static{ // we cannot intialise the values thus have to use static keyword
    ceo = "Khushi";
   }

   public Faltu(){
    i=90;
    j=12;
   }

   public Faltu(int i){
    this.i = i;
   }
}
