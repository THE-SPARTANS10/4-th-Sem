library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity dff is
port(
  D: in std_logic;
  clk: in std_logic;
  O: out std_logic
  );
end dff;

architecture behavioral of dff is
begin
  process(D,clk)
  begin
    if(clk'event and clk='1') then
      O<=D;
    end if;
  end process;
end behavioral;