library ieee;
use ieee.std_logic_1164.all;

entity three_input_nand is
port(
  a : in std_logic;
  b : in std_logic;
  c : in std_logic;
  y : out std_logic);
end three_input_nand;

architecture data_flow of three_input_nand is
begin
  y<=not(a and b and c);
end data_flow;