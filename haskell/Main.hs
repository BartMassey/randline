-- Copyright (c) 2018 Bart Massey
-- [This program is licensed under the "MIT License"]
-- Please see the file LICENSE in the source
-- distribution of this software for license terms.

module Main where

import Data.List (genericLength, genericIndex)
import System.Random (randomRIO)
import System.IO (getContents)

main :: IO ()
main = do
  lines <- fmap lines getContents
  let nlines = genericLength lines :: Integer
  index <- randomRIO (0, nlines - 1)
  putStrLn $ genericIndex lines index
