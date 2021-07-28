library ieee;
use ieee.std_logic_1164.all;

entity mux41 is
port
(
  I0: in std_logic;
  I1: in std_logic;
  I2: in std_logic;
  I3: in std_logic;
  S0: in std_logic;
  S1: in std_logic;
  Y: out std_logic;
);
end mux41;

architecture dataflow of mux41 is
  begin
    y<=(I0 and not(S0) and not(S1))or(I1 and not(S1) and S0)or(I2 and S1 and not(S0))or(I3 and S1 and S0);
end architecture;