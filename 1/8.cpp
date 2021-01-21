
Node* mergeLists(Node* first_node, Node* second_node){
    Node *head = NULL;
    if (first_node == NULL)
        return second_node;
    else if (second_node == NULL)
        return first_node;
    if (first_node->value >= second_node->value){
        head = second_node;
        head->next = mergeLists(first_node, second_node->next);
    }
    else{
        head = first_node;
        head->next = mergeLists(first_node->next, second_node);
    }
    Node *node;
    Node *equal = head;
    
    while (equal->next != NULL){
        if (equal->value != equal->next->value){
            equal = equal->next;
        }
        else{
            node = equal->next->next;
            free(equal->next);
            equal->next = node;
        }
    }
    return head;
}
