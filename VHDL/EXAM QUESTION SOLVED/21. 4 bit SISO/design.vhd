-----------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity DFF is
port(
  CLK,D: in std_logic;
  q: out std_logic);
end DFF;

architecture Partl of DFF is
begin
  process(CLK,D)
  begin
    if(CLK' event and CLK='1') then
    
    	if(D='0') then q<='0';
    	elsif(D='1') then q<='1';
   	  end if;
  end if;
  end process;
end Partl;
-----------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity SISO is
port(
	SISOCLK,INPUT : in std_logic;
    OUTPUT : out std_logic);
end SISO;

architecture Part2 of SISO is
component DFF is
port(
	CLK,D: in std_logic;
    q: out std_logic);
end component;

signal oup1,oup2,oup3 : std_logic;

begin

D1: DFF port map(SISOCLK,INPUT,oup1);
D2: DFF port map(SISOCLK,oup1,oup2);
D3: DFF port map(SISOCLK,oup2,oup3);
D4: DFF port map(SISOCLK,oup3,OUTPUT);

end Part2;