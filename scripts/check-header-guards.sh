#!/bin/sh
find -iname '*.h' | xargs ack -L pragma
