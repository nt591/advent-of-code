# day1


[![CircleCI](https://circleci.com/gh/yourgithubhandle/day1/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/day1/tree/master)


**Contains the following libraries and executables:**

```
day1@0.0.0
│
├─test/
│   name:    TestDay1.exe
│   main:    TestDay1
│   require: day1.lib
│
├─library/
│   library name: day1.lib
│   namespace:    Day1
│   require:
│
└─executable/
    name:    Day1App.exe
    main:    Day1App
    require: day1.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x Day1App.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
