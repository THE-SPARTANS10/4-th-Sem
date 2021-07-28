library IEEE;
use IEEE.std_logic_1164.all;
entity full_adder is
port(
    a: in std_logic_vector(2 downto 0);
    s: out std_logic_vector(1 downto 0));
end full_adder;
architecture rt1 of full_adder is begin
    process(a) is
    begin
    case a is
    when "000" = > s <= "00";
    when "001" = > s <= "10";
    when "010" = > s <= "10";
    when "011" = > s <= "01";
    when "100" = > s <= "10";
    when "101" = > s <= "01";
    when "110" = > s <= "01";
    when others = > s <= "11";
end case;
end process;
end rt1;