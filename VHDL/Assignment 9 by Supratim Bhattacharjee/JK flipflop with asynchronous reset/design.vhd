library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity jkff_async_reset is
port(
  J: in std_logic;
  K: in std_logic;
  clk: in std_logic;
  reset: in std_logic;
  O: out std_logic
  );
end jkff_async_reset;

architecture behavioral of jkff_async_reset is
begin
  process(J,K,clk,reset)
  begin
    if(reset='0') then
      O<='0';
    elsif(clk'event and clk='1') then
      if(j='0' and k='1') then
        O<='0';
      elsif(j='1' and k='0') then
        O<='1';
      elsif(j='1' and k='1') then
        O<=not(O); 
      end if;
    end if;
  end process;
end behavioral;