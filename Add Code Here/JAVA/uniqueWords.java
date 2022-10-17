import java.io.*;
//import java.util.Arrays;
import java.util.HashSet;

//Finds unique words in a text file using Hashset
public class UniqueWords {
    public static void main(String[] args) throws Exception {
        String line;
        FileReader file = new FileReader("src/main/resources/file.txt");
        BufferedReader br = new BufferedReader(file);
        HashSet<String> uniqueWords = new HashSet<>();
        while ((line = br.readLine()) != null) {
            //array to store the words in the text file
            String[] wordsArray = line.toLowerCase().split("\\W");
            //uniqueWords.addAll(Arrays.asList(wordsArray));
            for(String word : wordsArray)
            {
                //adding words in the array to Hashset to avoid duplicates
                uniqueWords.add(word);
            }
        }
        br.close();

    //printing each word in te Hashset uniqueWords
        for (String s : uniqueWords)
            System.out.println(s);
    }

}
