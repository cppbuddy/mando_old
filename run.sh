#!/bin/bash

bazelisk build --enable_bzlmod //src:mando
./bazel-bin/src/mando $@