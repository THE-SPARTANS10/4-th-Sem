library ieee;
use ieee.std_logic_1164.all;

entity two_input_xnor is
port(
  a : in std_logic;
  b : in std_logic;
  y : out std_logic);
end two_input_xnor;

architecture data_flow of two_input_xnor is
begin
  y<=(a and b) or (not(a) and not(b));
end data_flow;