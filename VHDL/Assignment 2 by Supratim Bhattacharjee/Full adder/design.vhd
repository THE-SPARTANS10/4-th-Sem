library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
port(
  x : in std_logic;
  y : in std_logic;
  z : in std_logic;
  s : out std_logic;
  c : out std_logic);
end full_adder;

architecture data_flow of full_adder is
begin
  s<=((x xor y) xor z);
  c<=((x and y) or ((x xor y) and z));
end data_flow;