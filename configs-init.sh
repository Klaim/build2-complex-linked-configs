bdep deinit -a && bdep config remove -a
rm -rf build-* .bdep *-host

# packages:
# A -> B -> C
# A->D
# A->E->C

# configurations (targets except "host"):
# host { C }
# X { A }
# Y {B, D }
# Z { E }

if command -v g++ &> /dev/null
then
    default_compiler=g++
else
    default_compiler=cl
fi

# As this is a complex setup, instead of using shortcut commands, we'll do each step separately.
# First: create each build configurations
bpkg create cc config.cxx=cl -d ./build-host --type host
bpkg create cc config.cxx=cl "config.cxx.coptions='/W4'" -d ./build-targetX
bpkg create cc config.cxx=clang++ "config.cxx.coptions=-O2 -Wall -Wextra -Weffc++ -pedantic" -d ./build-targetY
bpkg create cc config.cxx=clang++ "config.cxx.coptions=-g -Wall -Wextra -Weffc++ -pedantic" -d ./build-targetZ

# Prepare for initialization. Usually this is done with initialiazing packages/projects in one step,
# but we want to link the configurations before initializing the packages, so here we go:
bdep init --empty
# Prepare the configurations so that we can use bdep instead of bpkg (which is a lower level tool).
bdep config add build-targetX/ @targetX --default --forward
bdep config add build-targetY/ @targetY
bdep config add build-targetZ/ @targetZ
bdep config add build-host/ @host --no-default
# Link the configurations so that dependencies are found in the right configuration. (note that I could have used `bpkg link` with build configs paths, but it's shorter with `bdep`)
#  the targets to each other where it make sense:
bdep config link @targetX @targetY
bdep config link @targetX @targetZ
bdep config link @targetY @targetZ

# Now we can initialize the packages/projects in the right configurations:
# Beware, the order of initialization is important to be sure dependencies will not be automatically initialized in their user's configuration.
# bdep init -d ccc/ @host # Optional, use this if you want to debug that package too, otherwise it will be automatically initialized in the host config, but without the tests.
bdep init -d bbb/ @targetY
bdep init -d ddd/ @targetY
bdep init -d eee/ @targetZ
bdep init -d aaa/ @targetX

# Run tests but just for the main application:
echo "running: bdep test"
bdep test
# OR (because aaa/ is initialized in the 'forward' config)
echo "running: b test: aaa/"
b test: aaa/
# OR (because aaa/ is initialized in the 'forward' config)
echo "running: cd aaa/ && b test"
$(cd aaa/ && b test)
# OR explicitely specifying the build directory to build+test (useful in case where there are several variations of the same config like debug, release, asan...)
echo "running: b test: build-targetX/aaa/"
b test: build-targetX/aaa/

# Run all the tests from all the configurations
# Note that packages in @host will not have their tests setup except if you did manually set them up.
echo "running all the tests from all configs (except @host)"
bdep test --all

