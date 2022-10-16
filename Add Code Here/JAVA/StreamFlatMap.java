public class StreamTeste2 {
    public static void main(String[] args) {
        List<List<String>> nomes = new ArrayList<>();
        nomes.add(asList("Test", "Thanks for bigger letter"));
        nomes.add(asList("William", "Why did you go for this?"));
        List<String> collect = nomes.stream().flatMap(Collection::stream).collect(Collectors.toList());
        collect.stream().forEach(System.out::println);
        System.out.println(collect);

        List<String > palavras = asList("Olá", "Goku");
        String[] split = palavras.get(0).split("");
        System.out.println(Arrays.toString(split));
        List<String[]> collects = palavras.stream().map(p -> p.split("")).collect(Collectors.toList());
        List<String> collect1 = palavras.stream() //Stream<String>
                .map(p -> p.split(""))//Stream<String[]>
                .flatMap(Arrays::stream) // Stream<String>;
                .collect(Collectors.toList());
        System.out.println(collect1);
    }
