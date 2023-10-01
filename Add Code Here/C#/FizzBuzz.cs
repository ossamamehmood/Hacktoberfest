// Happy Hacktoberfest everyone! 
// I hope you all have a good time while participating. :-)

Dictionary<int, string> rules = new Dictionary<int, string>(); 
rules.Add(3, "Fizz");
rules.Add(5, "Buzz");

for (int i = 1; i <= 100; i++) {
    string word = "";

    foreach(KeyValuePair<int, string> rule in rules) {
        if (i % rule.Key == 0) {
            word += rule.Value;
        }
    }

    if (word != string.Empty) {
        Console.WriteLine(word);
    } else {
        Console.WriteLine(i);
    }
}