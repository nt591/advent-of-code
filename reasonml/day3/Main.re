/* Module approach cuz trying a new thing */

let file = "input.txt";

module Main = {
  include Str
  module Int_set =
    Set.Make({
      type t = (int, int);
      let compare = ((x0, y0), (x1, y1)) =>
        switch (Pervasives.compare(x0, x1)) {
        | 0 => Pervasives.compare(y0, y1)
        | c => c
        };
    });


  type point = (int, int);

  let parseInput = fileName => {
    let channel = open_in(fileName);
    let directionsList = ref([]);

    try (
      {
        while (true) {
          let line = input_line(channel);
          let directions = Str.split(Str.regexp(","), line);
          directionsList := [directions, ...directionsList^];
        };
        directionsList^;
      }
    ) {
      | End_of_file =>
        close_in(channel);
        List.rev(directionsList^);
    }
  }

  exception InvalidDirection;

  let directionToPath = direction => {
    let dir = String.get(direction, 0);
    let value = int_of_string(
      String.sub(direction, 1, String.length(direction) - 1)
    );

    switch(dir) {
      | 'U' => (value, 0);
      | 'D' => (-value, 0);
      | 'L' => (0, -value);
      | 'R' => (0, value);
      | _ => print_endline("Can't raise"); (0, 0);
    }
  }

  let generatePoint = (oldPoint, direction) => {
    let (oldX, oldY) = oldPoint;
    let (pathX, pathY) = directionToPath(direction);
    (oldX + pathX, oldY + pathY);
  }

  let generateWire = (list, index) => {
    let directions = List.nth(list, index);
    let paths = List.append([(0, 0)], List.map(directionToPath, directions));
    // start to update each element with the sum of the previous paths
    List.mapi((idx, (x, y) as path) => {
      if (idx == 0) {
        path
      } else {
        // get the last element
        let (lastX, lastY) = List.nth(paths, idx - 1);
        (x + lastX, y + lastY);
      }
    }, paths)
  }

  let findSmallestIntersection = (wire1, wire2) => {
    // first element in each is origin, so let's remove
    let w1 = switch(wire1) {
      | [] => []
      | [_, ...tl] => tl
    }
    let w2 = switch(wire2) {
      | [] => []
      | [_, ...tl] => tl
    }

    // get the set intersection
    let toSet = List.fold_left((acc, x) => { Int_set.add(x, acc) }, Int_set.empty);
    let s1 = toSet(w1);
    let s2 = toSet(w2);

    let intersections = Int_set.inter(s1, s2);
    Int_set.min_elt(intersections)
  }

  let manhattan = ((x, y)) => abs(x) + abs(y)

  let run = file => {
    let parsedInput = parseInput(file);
    let firstWire = generateWire(parsedInput, 0);
    let secondWire = generateWire(parsedInput, 1);
    let distance = manhattan(findSmallestIntersection(firstWire, secondWire))
    print_endline("works")
    print_endline(string_of_int(distance));
  };
}

let () = Main.run(file);
