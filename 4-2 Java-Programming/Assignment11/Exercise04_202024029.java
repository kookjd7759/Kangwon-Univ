package week13;

class TransactionException extends Exception {}
class AccountException extends Exception {}
class InvalidAmountException extends TransactionException {}
class ExcessiveWithdrawException extends TransactionException {}
class AccountNotFoundException extends AccountException {}
class AccountFrozenException extends AccountException {}

class BankService {
    public void transfer(String accountId, int amount)
            throws AccountNotFoundException, AccountFrozenException,
                   InvalidAmountException, ExcessiveWithdrawException {

        if (accountId == null) throw new AccountNotFoundException();

        if (accountId.equals("frozen")) throw new AccountFrozenException();

        if (amount < 0) throw new InvalidAmountException();

        if (amount > 1000000) throw new ExcessiveWithdrawException();
    }
}

public class Exercise04_202024029 {
	private static void test(int idx, String accountId, int amount) {
		System.out.print("Case " + idx + ": ");
		BankService service = new BankService();

        try {
            service.transfer(accountId, amount);
            System.out.println("[성공] " + amount + "원 이체 완료.");
        } catch (AccountNotFoundException e) {
            System.out.println("[계좌 오류] 계좌를 찾을 수 없습니다.");
        } catch (AccountFrozenException e) {
            System.out.println("[계좌 오류] 동결된 계좌입니다.");
        } catch (InvalidAmountException e) {
            System.out.println("[거래 오류] 이체 금액(" + amount + ")이 올바르지 않습니다.");
        } catch (ExcessiveWithdrawException e) {
            System.out.println("[거래 오류] 이체 한도(100만원)를 초과했습니다.");
        }
	}
	
    public static void main(String[] args) {
    	test(1, "Kook", 50000);
    	test(2, null, 50000);
    	test(3, "frozen", 50000);
    	test(4, "Kook", -500);
    	test(5, "Kook", 5000000);
    }
}
