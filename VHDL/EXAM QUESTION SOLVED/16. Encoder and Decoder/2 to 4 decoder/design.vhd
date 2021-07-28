library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity decoder24 is
port(
  A: in std_logic;
  B: in std_logic;
  O0: out std_logic;
  O1: out std_logic;
  O2: out std_logic;
  O3: out std_logic;
  );
end decoder24;

architecture behavioral of decoder24 is
  begin
  process(a,b)
    begin
	  if(A='0' and B='0') then
        O0<='1';
        O1<='0';
        O2<='0';
        O3<='0';
      elsif(A='0' and B='1') then
        O0<='0';
        O1<='1';
        O2<='0';
        O3<='0';
      elsif(A='1' and B='0') then
        O0<='0';
        O1<='0';
        O2<='1';
        O3<='0';
      else
        O0<='0';
        O1<='0';
        O2<='0';
        O3<='1';
      end if;
  end process;
end behavioral;
