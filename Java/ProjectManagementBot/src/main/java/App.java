import org.hibernate.SessionFactory;
import repository.HibernateUtil;
import view.TelegramView;


public class App {

    private static final SessionFactory sessionFactory = HibernateUtil.getSessionFactory();
    public static void main(String[] args) {
        TelegramView telegramView = new TelegramView();
        telegramView.startDialog();
    }
}
