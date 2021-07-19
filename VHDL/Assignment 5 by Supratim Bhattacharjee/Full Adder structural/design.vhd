library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity full_adder is
port(
  A: in std_logic;
  B: in std_logic;
  Cin: in std_logic;
  Sum: out std_logic;
  Cout: out std_logic);
end full_adder;

architecture structural of full_adder is

signal temp1,temp2,temp3: std_logic;

component half_adder is
port(
  x: in std_logic;
  y: in std_logic;
  s: out std_logic;
  c: out std_logic);
end component;

component or_gate is
port(
  p: in std_logic;
  q: in std_logic;
  y: out std_logic);
end component;

begin
  HA1: half_adder port map(x=>A,y=>B,c=>temp1,s=>temp2);
  HA2: half_adder port map(x=>temp2,y=>Cin,c=>temp3,s=>Sum);
  OR1: or_gate port map(p=>temp1,q=>temp3,y=>Cout);

end structural;

------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity half_adder is
port(
  x: in std_logic;
  y: in std_logic;
  s: out std_logic;
  c: out std_logic);
end half_adder;

architecture arch_ha of half_adder is
begin
  s<=x xor y;
  c<=x and y;
end arch_ha;

------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity or_gate is
port(
  p: in std_logic;
  q: in std_logic;
  y: out std_logic
);
end or_gate;

architecture arch_or of or_gate is
begin
  y<=p or q;
end arch_or;