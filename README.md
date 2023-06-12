![CI](https://github.com/Pavel-Durov/dynamorio.poc/actions/workflows/pr-ci.yml/badge.svg)

# dbi.poc

Repository containing code and documentation of Dynamic Binary Instrumentation (DBI) frameworks exploration.

## Docs
+ [DBI](./docs/DBI.md)
+ [DynamoRIO](./docs/DynamoRIO.md)

## Prerequisites
- Make sure you have [direnv](https://direnv.net/)(version >= 2.25.2) installed
- Make sure you have [cmake](https://cmake.org/)(version >= 3.22.1) installed
- Set `DRIO_HOME` varible in [.envrc](./.envrc), pointing towards where DynamoRIO is located on the machine
- Run `direnv allow`, or source [.envrc](./.envrc) file if you don't like `direnv`

## Setup
```shell
$ setup
``` 
> This command should download and setup local version of DynamoRIO framework.

## Build

```shell
$ build
``` 

## Run

```shell
$ run
```

## All-together now
```shell
$ direnv allow && build && run
```
