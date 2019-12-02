/* let's start by reading a file */

let file = "input.txt";

let readFile = fileName => {
  let channel = open_in(fileName);
  let lines = ref([]);
  try (
    {
      while (true) {
        lines := [input_line(channel), ...lines^];
      };
      lines^;
    }
  ) {
  | End_of_file =>
    close_in(channel);
    List.rev(lines^);
  }
}

let fuelFormula = mass => (mass / 3) - 2
let lines = List.map(int_of_string, readFile(file))

let reduce = (fn, list) => List.fold_left(fn, 0, list);

let fuelRequired = reduce((acc, el) => acc + (fuelFormula(el)))

let rec fuelRecursive = (accumulated, mass) => {
  let required = fuelFormula(mass);
  if (required > 0) {
    fuelRecursive(accumulated + required, required)
  } else {
    accumulated
  }
}

let fuelRequiredTotal = reduce(fuelRecursive)

let main = () => {
  let p1 = fuelRequired(lines);
  let p2 = fuelRequiredTotal(lines);
  print_endline(Printf.sprintf("Part 1: %d", p1));
  print_endline(Printf.sprintf("Part 2: %d", p2));
}

let () = main();
