library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity mux41 is
port(
  D0: in std_logic;
  D1: in std_logic;
  D2: in std_logic;
  D3: in std_logic;
  S1: in std_logic;
  S0: in std_logic;
  O: out std_logic;
  );
end mux41;

architecture structural of mux41 is

signal temp1,temp2: std_logic;

component mux21 is
port(
  I0: in std_logic;
  I1: in std_logic;
  S: in std_logic;
  Y: out std_logic;);
end component;

begin
  mux1: mux21 port map(I0=>D0,I1=>D1,S=>S0,Y=>temp1);
  mux2: mux21 port map(I0=>D2,I1=>D3,S=>S0,Y=>temp2);
  mux3: mux21 port map(I0=>temp1,I1=>temp2,S=>S1,Y=>O);

end structural;

------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity mux21 is
port(
  I0: in std_logic;
  I1: in std_logic;
  S: in std_logic;
  Y: out std_logic;);
end mux21;

architecture arch_mux21 of mux21 is
  begin
    process(I0,I1,S)
    begin
    if(S<='0') then
      Y<=I0;
    else
      Y<=I1;
    end if;
  end process;
end arch_mux21;