library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity mux81 is
port(
  I0: in std_logic;
  I1: in std_logic;
  I2: in std_logic;
  I3: in std_logic;
  I4: in std_logic;
  I5: in std_logic;
  I6: in std_logic;
  I7: in std_logic;
  S2: in std_logic;
  S1: in std_logic;
  S0: in std_logic;
  OP: out std_logic;
  );
end mux81;

architecture structural of mux81 is

signal temp1,temp2: std_logic;

component mux41 is
port(
  a: in std_logic;
  b: in std_logic;
  c: in std_logic;
  d: in std_logic;
  sel1: in std_logic;
  sel0: in std_logic;
  o: out std_logic;);
end component;

component mux21 is
port(
  x: in std_logic;
  y: in std_logic;
  sel2: in std_logic;
  z: out std_logic;);
end component;

begin
  mux1: mux41 port map(a=>I0,b=>I1,c=>I2,d=>I3,sel1=>S1,sel0=>S0,o=>temp1);
  mux2: mux41 port map(a=>I4,b=>I5,c=>I6,d=>I7,sel1=>S1,sel0=>S0,o=>temp2);
  mux3: mux21 port map(x=>temp1,y=>temp2,sel2=>S2,z=>OP);

end structural;

------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity mux41 is
port(
  a: in std_logic;
  b: in std_logic;
  c: in std_logic;
  d: in std_logic;
  sel1: in std_logic;
  sel0: in std_logic;
  o: out std_logic;);
end mux41;

architecture arch_mux41 of mux41 is
  begin
    process(a,b,c,d,sel1,sel0)
    begin
      if(sel1<='0' and sel0<='0') then
        o<=a;
      elsif(sel1<='0' and sel0<='1') then
        o<=b;
      elsif(sel1<='1' and sel0<='0') then
        o<=c;
      else
        o<=d;
    end if;
  end process;
end arch_mux41;

------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity mux21 is
port(
  x: in std_logic;
  y: in std_logic;
  sel2: in std_logic;
  z: out std_logic;);
end mux21;

architecture arch_mux21 of mux21 is
  begin
    process(x,y,sel2)
    begin
      if(sel2<='0') then
        z<=x;
      else
        z<=y;
    end if;
  end process;
end arch_mux21;