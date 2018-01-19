-- Copyright (c) 2018 Bart Massey
-- [This program is licensed under the "MIT License"]
-- Please see the file LICENSE in the source
-- distribution of this software for license terms.

module Main where

import System.Random (randomRIO)
import System.IO (getContents)

main :: IO ()
main = do
  lines <- fmap lines getContents
  index <- randomRIO (0, length lines - 1)
  putStrLn $ lines !! index
