#!/bin/bash

bazelisk build --enable_bzlmod //:mando
./bazel-bin/mando $@