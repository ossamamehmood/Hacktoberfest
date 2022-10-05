function filterItemByAvailability() {
  // Array with item to filter
  const item = [
    {
      id: "1",
      name: "Spicy Instant Noodle",
      availability: true,
    },
    {
      id: "2",
      name: "Limited Item A",
      availability: false,
    },
    {
      id: "3",
      name: "Cute Plushie",
      availability: true,
    },
  ];
  // Log initial array item
  console.log(item);

  // empty array to store available item
  const result = [];

  // loop through item array, filter avalability attribute
  for (const data of item) {
    if (data.availability) {
      result.push(data);
    }
  }

  // Log final array item or available item
  console.log(result);
}
filterItemByAvailability();
