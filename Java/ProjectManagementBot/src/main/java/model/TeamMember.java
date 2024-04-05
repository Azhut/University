package model;

/**
 * Член команды
 */
public class TeamMember {

    private String memberID;
    private Role role;

    public TeamMember(String memberID, Role role) {
        this.memberID = memberID;
        this.role = role;
    }

    private void setMemberID(String memberID) {
        this.memberID = memberID;
    }

    public void setRole(Role role) {
        this.role = role;
    }

    public String getMemberID() {
        return memberID;
    }

    public Role getRole() {
        return role;
    }
}